#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const int K = 224;
const int H = 256;

int x, k;
double dp[K][H][2][K], p;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> k >> p; p /= 100;

    int last8 = x & 255;
    x >>= 8;
    if (x) {
        int bit = x & 1, count = 0;
        while (((x >> count) & 1) == bit) ++count;
        dp[0][last8][bit][count] = 1;
    } else {
        dp[0][last8][0][0] = 1;
    }

    for (int i = 0; i < k; ++i) {
        for (int h = 0; h < 256; ++h)
        for (int bit = 0; bit <= 1; ++bit) 
        for (int count = 0; count < K; ++count) {
            const double q = dp[i][h][bit][count];
            if (q == 0) continue;

            // cout << i << " " << h << " " << bit << " " << count << endl;

            // x *= 2
            if (count == 0) {
                if (h * 2 >= 256) {
                    dp[i+1][(h << 1) & 255][1][1] += p * q;
                } else {
                    dp[i+1][h << 1][0][0] += p * q;
                }
            } else {
                int new_bit = (h >> 7) & 1;
                if (bit == new_bit) {
                    dp[i+1][(h<<1)&255][bit][count+1] += p * q;
                } else {
                    dp[i+1][(h<<1)&255][new_bit][1] += p * q;
                }
            }

            // x += 1
            if (h == 255) {
                if (count == 0 || !bit) {
                    dp[i+1][0][1][1] += (1-p)*q;
                } else {
                    dp[i+1][0][0][count] += (1-p)*q;
                }
            } else {
                dp[i+1][h+1][bit][count] += (1-p)*q;
            }
        }
    }

    double ans = 0;
    for (int h = 2; h < 256; h += 2) {
        int lg = 0, x = h;
        while(~x & 1) ++lg, x >>= 1;
        for (int z = 0; z < 2; ++z)
        for (int count = 0; count < K; ++count) {
            ans += lg * dp[k][h][z][count];
        }
    }

    for (int count = 1; count < K; ++count) ans += 8 * dp[k][0][1][count];
    for (int count = 1; count < K; ++count) ans += (8+count) * dp[k][0][0][count];
    cout << fixed << setprecision(14) << ans << '\n';
}
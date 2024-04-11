#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        vector<vector<vector<int>>> cnt(4, vector<vector<int>>(4, vector<int>(4)));
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            cnt[x[j] % 4][y[j] % 4][abs(gcd(x[i] - x[j], y[i] - y[j])) % 4]++;
        }
        int x0 = x[i] % 4, y0 = y[i] % 4;
        for(int x1 = 0; x1 < 4; ++x1) {
            for(int y1 = 0; y1 < 4; ++y1) {
                for(int z1 = 0; z1 < 4; ++z1) {
                    if(!cnt[x1][y1][z1]) continue;
                    for(int x2 = x1; x2 < 4; ++x2) {
                        for(int y2 = x1 == x2 ? y1 : 0; y2 < 4; ++y2) {
                            if((x1 - x2) % 2 || (y1 - y2) % 2) continue;
                            for(int z2 = x1 == x2 && y1 == y2 ? z1 : 0; z2 < 4; ++z2) {
                                if(!cnt[x2][y2][z2]) continue;
                                int s = (x2 - x0) * (y1 - y0) - (x1 - x0) * (y2 - y0);
                                int e = z1 + z2 + gcd(abs(x1 - x2), abs(y1 - y2));
                                if(s % 2 == 0 && e % 2 == 0 && (s / 2 + e / 2) % 2 == 0) {
                                    int c1 = cnt[x1][y1][z1], c2 = cnt[x2][y2][z2];
                                    int p = z1 % 2 ? 3 : 1;
                                    if(x1 == x2 && y1 == y2 && z1 == z2) {
                                        ans += p * c1 * (c1 - 1) / 2;
                                    } else {
                                        ans += p * c1 * c2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans / 3 << endl;
}
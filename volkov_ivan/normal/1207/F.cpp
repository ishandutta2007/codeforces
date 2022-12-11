#include <iostream>
#include <cstring>

using namespace std;

const int K = 700, MAX_N = 5e5 + 7;

int cnt[K][K];
int a[MAX_N];

int main() {
    memset(cnt, 0, sizeof(cnt));
    memset(a, 0, sizeof(a));
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] += y;
            for (int rest = 1; rest < K; rest++) cnt[rest][x % rest] += y;
        } else {
            if (x < K) cout << cnt[x][y] << "\n";
            else {
                int res = 0;
                for (int i = y; i < MAX_N; i += x) res += a[i];
                cout << res << "\n";
            }
        }
    }
    return 0;
}
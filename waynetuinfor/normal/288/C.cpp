#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, lg = 30;
int p[maxn];

int main() {
    int n; cin >> n;
    int nn = n;
    long long ans = 0;
    while (n > 0) {
        int bit = -1;
        for (int i = lg; i >= 0; --i) {
            if ((1 << i) & n) {
                bit = i;
                break;
            } 
        }
        int cur = -1;
        for (int i = 0; i <= n; ++i) {
            if ((1 << bit) & i) {
                cur = i;
                break;
            }
        }
        int ub = cur, lb = cur - 1;
        while (lb >= 0 && ub <= n) {
            p[ub] = lb;
            p[lb] = ub;
            ans += 2 * (lb ^ ub);
            ++ub; --lb;
        }
        n = lb;
    }
    cout << ans << endl;
    for (int i = 0; i <= nn; ++i) cout << p[i] << ' '; cout << endl;
    return 0;
}
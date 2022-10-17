#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &it : a) {
            cin >> it;
        }
        sort(all(a));
        int answer = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum <= x) {
                answer += (x - sum) / (i + 1) + 1;
            }
            //cerr << answer << '\n';
        }
        cout << answer << '\n';
    }
}
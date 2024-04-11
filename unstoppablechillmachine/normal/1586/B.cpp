#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        set<int> l;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            l.insert(b);
        }
        int root = 0;
        for (int i = 1; i <= n; i++) {
            if (!l.count(i)) {
                root = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i != root) {
                cout << i << ' ' << root << '\n';
            }
        }
    }
}
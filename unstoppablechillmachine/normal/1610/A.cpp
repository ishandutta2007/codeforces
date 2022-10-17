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
        if (n == 1 && m == 1) {
            cout << 0 << '\n';
        } else if (n == 1 || m == 1) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}
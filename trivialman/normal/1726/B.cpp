#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 505;
mt19937 rng(time(0));

int T, m, n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n % 2 == 0) {
            if (m % 2 == 1 || m < n)
                cout << "NO\n";
            else {
                cout << "YES\n";
                rep(i, 1, n - 2) cout << "1 ";
                int x = (m - n + 2) / 2;
                cout << x << " " << x << "\n";
            }
        } else {
            if (m < n)
                cout << "NO\n";
            else {
                cout << "YES\n";
                rep(i, 1, n - 1) cout << "1 ";
                cout << m - n + 1 << "\n";
            }
        }
    }
    return 0;
}
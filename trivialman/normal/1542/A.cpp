#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 5005;

int T, n, x;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        int nodd = 0;
        rep(i, 1, n * 2) {
            cin >> x;
            nodd += (x % 2);
        }
        cout << (nodd == n ? "YES" : "NO") << endl;
    }
    return 0;
}
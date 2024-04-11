#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 9e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, m, x;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        m = 0;
        rep(i, 1, n) cin >> x, m += abs(x % 2);
        if (m % 4 == 0 || m % 4 == 3)
            cout << "Alice\n";
        else if (m % 4 == 2)
            cout << "Bob\n";
        else {
            if (n % 2 == 0)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
    return 0;
}
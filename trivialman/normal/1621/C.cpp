#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 10005;
mt19937 rng(time(0));

int T, n;
int ans[N];

int ask(int x) {
    int res;
    cout << "? " << x << endl;
    cin >> res;
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) ans[i] = 0;
        rep(i, 1, n) if (!ans[i]) {
            while (ask(i) != i)
                ;
            int x = i;
            while (1) {
                ans[x] = ask(i);
                x = ans[x];
                if (x == i)
                    break;
            }
        }
        cout << "!";
        rep(i, 1, n) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}
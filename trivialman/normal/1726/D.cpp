#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 2e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, m;
int x[N], y[N], fa[N];
char ans[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        rep(i, 1, n) fa[i] = i;
        ans[m + 1] = 0;
        set<int> st;
        rep(i, 1, m) {
            cin >> x[i] >> y[i];
            int px = find(x[i]), py = find(y[i]);
            if (px != py)
                ans[i] = '0', fa[px] = py;
            else
                ans[i] = '1', st.insert(x[i]), st.insert(y[i]);
        }
        if (m == n + 2 && st.size() == 3) {
            // 1 is cycle
            rep(i, 1, m) if (ans[i] == '1') {
                rep(j, 1, n) fa[j] = j;
                fa[x[i]] = y[i];
                rep(j, 1,
                    m) if (ans[j] == '0' && x[j] != x[i] && y[j] != x[i]) {
                    int px = find(x[j]), py = find(y[j]);
                    fa[px] = py;
                }
                rep(j, 1, m) if (ans[j] == '0' &&
                                 (x[j] == x[i] || y[j] == x[i]) &&
                                 find(x[j]) == find(y[j])) {
                    swap(ans[i], ans[j]);
                    break;
                }
                break;
            }
        }
        cout << (ans + 1) << "\n";
    }
    return 0;
}
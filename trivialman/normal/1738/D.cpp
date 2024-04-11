#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
#define ar3 array<int, 3>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 2e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, k;
int a[N], in[N], out[N];
vector<int> g[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) g[i].clear();

        int l = 0, r = n + 1;
        rep(i, 1, n) {
            cin >> a[i];
            l = max(l, min(i, a[i]));
            r = min(r, max(i, a[i]));
            if (a[i] > 0 && a[i] < n + 1)
                g[a[i]].PB(i), out[a[i]]++, in[i]++;
        }
        cout << l << "\n";

        set<ar3> st;
        rep(i, 1, n) st.insert({in[i], out[i], i});

        rep(i, 1, n) {
            auto ele = *st.begin();
            st.erase(ele);
            int x = ele[2];
            for (auto u : g[x]) {
                st.erase({in[u], out[u], u});
                out[x]--, in[u]--;
                st.insert({in[u], out[u], u});
            }
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// const LL P = 1e9 + 7;
LL P = 1e9 + 7;
const int N = 2e5 + 5;
const LL INF = (1ll << 62) - 1;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, x;
int b[N];
vector<int> a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        set<int> st;
        rep(i, 1, n) cin >> x, a[x].PB(i), st.insert(x);
        while (st.size() > 1) {
            vector<int> tmp;
            for (auto x : st)
                tmp.PB(x);
            int sz = tmp.size();
            rep(i, 0, sz - 1) {
                int x = tmp[i], sz1 = a[x].size(), y = a[x][sz1 - 1];
                b[y] = tmp[(i + 1) % sz];
                a[x].pop_back();
                if (!a[x].size())
                    st.erase(x);
            }
        }
        if (st.size()) {
            int x = *st.begin();
            for (auto y : a[x])
                b[y] = x;
            a[x].clear();
        }
        rep(i, 1, n) cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}
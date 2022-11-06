#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], prv[maxn], nxt[maxn], g[maxn];
bool line[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    g[0] = 2; g[n + 1] = 2;
    for (int i = 0; i < n; ++i) g[i + 1] = (s[i] == 'B'); 
    for (int i = 1; i <= n; ++i) cin >> a[i];
    set<pair<int, int>> st;
    for (int i = 1; i <= n; ++i) {
        prv[i] = i - 1;
        nxt[i] = i + 1;
        if (g[i] + g[i + 1] == 1) {
            st.insert(make_pair(abs(a[i] - a[i + 1]), i));
            line[i] = true;
        }
    }
    vector<pair<int, int>> ans;
    while (st.size()) {
        int v, p;
        tie(v, p) = *st.begin();
        st.erase(st.begin());
        ans.emplace_back(p, nxt[p]);
        if (line[nxt[p]]) {
            line[nxt[p]] = false;
            int to = nxt[nxt[p]];
            st.erase(make_pair(abs(a[to] - a[nxt[p]]), nxt[p]));
        } 
        if (prv[p] >= 1 && line[prv[p]]) {
            line[prv[p]] = false;
            st.erase(make_pair(abs(a[prv[p]] - a[p]), prv[p]));
        }
        if (prv[p] >= 1 && nxt[nxt[p]] <= n) {
            if (g[prv[p]] + g[nxt[nxt[p]]] == 1) {
                st.insert(make_pair(abs(a[prv[p]] - a[nxt[nxt[p]]]), prv[p]));
                line[prv[p]] = true;
            }
        }
        nxt[prv[p]] = nxt[nxt[p]];
        prv[nxt[nxt[p]]] = prv[p];
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first << ' ' << i.second << endl;
}
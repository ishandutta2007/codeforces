#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int pos[maxn], a[maxn], b[maxn];
vector<int> v[maxn];

int count(int x, int p) {
    return v[x].size() - (lower_bound(v[x].begin(), v[x].end(), p) - v[x].begin());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(pos, -1, sizeof(pos));
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        v[a[i]].push_back(i);
        pos[a[i]] = i;
    }
    set<pair<int, int>> st;
    for (int i = 1; i <= n; ++i) {
        if (pos[i] != -1) st.insert(make_pair(pos[i], i));
    }
    int q; cin >> q; while (q--) {
        int k; cin >> k; 
        vector<int> del;
        while (k--) {
            int l; cin >> l;
            if (pos[l] == -1) continue;
            st.erase(make_pair(pos[l], l));
            del.push_back(l);
        }
        if (st.size() == 0) {
            cout << "0 0" << endl;
            for (int l : del) st.insert(make_pair(pos[l], l));
            continue;
        }
        auto it = st.rbegin();
        int bst = it->second;
        int d = 1, p = v[bst].size() - 1; while (d < v[bst].size()) d <<= 1;
        while (d >>= 1) if (p - d >= 0) {
            int c = 0;
            for (int l : del) c += count(l, v[bst][p - d]);
            c += v[bst].size() - (p - d);
            if (n - v[bst][p - d] + 1 == c) p -= d;
        }
        cout << bst << ' ' << b[v[bst][p]] << endl;
        for (int l : del) st.insert(make_pair(pos[l], l));
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int a[maxn], ll[maxn], rl[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (q--) {
        int l, r; cin >> l >> r;
        vector<int> vec;
        for (int i = l; i < r; ++i) vec.push_back(abs(a[i + 1] - a[i]));
        stack<pair<int, int>> st;
        int ind = 0;
        memset(ll, 0, sizeof(ll)); memset(rl, 0, sizeof(rl));
        while (ind < vec.size()) {
            if (!st.size()) st.push(make_pair(vec[ind], ind)), ++ind;
            while (st.size() && ind < vec.size() && vec[ind] < st.top().first) st.push(make_pair(vec[ind], ind)), ++ind;
            while (ind < vec.size() && st.size() && vec[ind] >= st.top().first) ll[st.top().second] = ind - st.top().second, st.pop();
        }
        while (st.size()) ll[st.top().second] = vec.size() - st.top().second, st.pop();
        ind = vec.size() - 1;
        while (ind >= 0) {
            if (!st.size()) st.push(make_pair(vec[ind], ind)), --ind;
            while (st.size() && ind >= 0 && vec[ind] <= st.top().first) st.push(make_pair(vec[ind], ind)), --ind;
            while (ind >= 0 && st.size() && vec[ind] > st.top().first) rl[st.top().second] = st.top().second - ind, st.pop();
        }
        while (st.size()) rl[st.top().second] = st.top().second + 1, st.pop();
        long long ans = 0;
        for (int i = 0; i < vec.size(); ++i) ans += (long long)vec[i] * (long long)(rl[i]) * (long long)(ll[i]);
        cout << ans << endl;
    }
    return 0;
}
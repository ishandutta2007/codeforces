#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], dp[maxn], tag[maxn], pos[maxn], nowmax[maxn];

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] = max(dat[p], v); }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v = max(v, dat[p]); return v; }
} bit;

int cal(int n) {
    vector<int> v; v.push_back(a[1]);
    for (int i = 2; i <= n; ++i) {
        if (a[i] > v.back()) v.push_back(a[i]);
        else *lower_bound(v.begin(), v.end(), a[i]) = a[i];
    }
    return (int)v.size();
}

vector<int> solve(const vector<int> &vec) {
    if (vec.size() == 0) return vector<int>();
    vector<int> v, forb;
    v.push_back(a[vec[0]]);
    memset(pos, -1, sizeof(pos));
    // cout << "solve" << endl;
    // for (int i : vec) cout << i << ' '; cout << endl;
    pos[0] = 0;
    for (int i = 1; i < vec.size(); ++i) {
        if (a[vec[i]] > v.back()) {
            v.push_back(a[vec[i]]);
            int p = v.size() - 1;
            if (pos[p] == -1) pos[p] = i;
            else forb.push_back(vec[i]), forb.push_back(vec[pos[p]]);
        } else {
            int p = lower_bound(v.begin(), v.end(), a[vec[i]]) - v.begin();
            // cout << "i = " << i << " p = " << p << endl;
            if (pos[p] == -1) pos[p] = i;
            else forb.push_back(vec[i]), forb.push_back(vec[pos[p]]);
            v[p] = a[vec[i]];
        }
    }
    sort(forb.begin(), forb.end());
    forb.resize(unique(forb.begin(), forb.end()) - forb.begin());
    return forb;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int lis = cal(n);
    bit.init();
    for (int i = 1; i <= n; ++i) {
        dp[i] = bit.qry(a[i] - 1) + 1;
        bit.add(a[i], dp[i]);
    }
    vector<int> use, ans1;
    for (int i = 1; i <= n; ++i) nowmax[i] = 0;
    for (int i = n; i > 0; --i) {
        if (dp[i] < lis && nowmax[dp[i] + 1] <= a[i]) ans1.push_back(i);
        else use.push_back(i), nowmax[dp[i]] = max(nowmax[dp[i]], a[i]);
    }
    reverse(use.begin(), use.end());
    vector<int> ans2 = solve(use);
    for (int i : ans1) tag[i] = 1;
    for (int i : ans2) tag[i] = 2;
    for (int i = 1; i <= n; ++i) {
        if (tag[i] == 1) cout << 1;
        else if (tag[i] == 2) cout << 2;
        else cout << 3;
    }
    cout << endl;
    return 0;
}
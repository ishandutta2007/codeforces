#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
int ls[maxn], rs[maxn], good[maxn], a[maxn], cp[maxn];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 1; i <= n; ++i) a[i] = s[i - 1] - 'a';
    for(int i = 1; i <= n; ++i) cin >> ls[i] >> rs[i];

    vector<int> b;
    function<void(int)> dfs = [&](int u) {
        if(ls[u]) dfs(ls[u]);
        b.push_back(u);
        if(rs[u]) dfs(rs[u]);
    };
    dfs(1);

    good[b[n - 1]] = 0;
    for(int i = n - 2; i >= 0; --i) {
        if(a[b[i]] < a[b[i + 1]] || (a[b[i]] == a[b[i + 1]] && good[b[i + 1]])) good[b[i]] = 1;
    }

    function<void(int)> dfs2 = [&](int u) {
        if(!u) return;
        vector<int> c;
        int p = u;
        while(p && !good[p]) {
            c.push_back(p);
            p = ls[p];
        }
        if(good[p] && c.size() + 1 <= k) {
            k -= c.size() + 1;
            cp[p] = 1, dfs2(ls[p]), dfs2(rs[p]);
            while(!c.empty()) {
                cp[c.back()] = 1, dfs2(rs[c.back()]), c.pop_back();
            }
        }
    };
    dfs2(1);

    string ans;
    function<void(int)> dfs3 = [&](int u) {
        if(ls[u]) dfs3(ls[u]);
        ans += a[u] + 'a';
        if(cp[u]) ans += a[u] + 'a';
        if(rs[u]) dfs3(rs[u]);
    };
    dfs3(1);

    cout << ans << '\n';
}
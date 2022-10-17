#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ufind {
    vector<int> par, sz;
    ufind(int n) : par(n), sz(n, 1) {
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int x) {
        if(x != par[x]) return par[x] = find(par[x]);
        return x;
    }
    int size(int x) {
        return sz[find(x)];
    }
    int same(int u, int v) {
        return find(u) == find(v);
    }
    int merge(int u, int v) {
        int x = find(u), y = find(v);
        if(x == y) return 0;
        if(sz[x] < sz[y]) swap(sz[x], sz[y]), swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return 1;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, d;
    cin >> n >> d;
    ufind uf(n);
    int cnt = 0;
    for(int i = 0; i < d; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if(!uf.merge(u, v)) ++cnt;
        vector<int> a;
        for(int j = 0; j < n; ++j) {
            if(uf.find(j) == j) {
                a.push_back(uf.size(j));
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        int ans = 0;
        for(int j = 0; j <= cnt && j < a.size(); ++j) ans += a[j];
        cout << ans - 1 << '\n';
    }
}
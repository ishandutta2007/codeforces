#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 5;
int par[N], w[N], sz[N];
priority_queue<int> s[N];
priority_queue<int, vector<int>, greater<int>> ms[N];
ll ans = 0;
int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}
void merge(int u, int v) {
    int x = find(u), y = find(v);
    if(sz[x] > sz[y]) swap(x, y);
    w[y] += w[x];
    sz[y] += sz[x];
    par[x] = y;
    while(!s[x].empty()) {
        s[y].push(s[x].top());
        s[x].pop();
    }
    while(!ms[x].empty()) {
        s[y].push(ms[x].top());
        ans -= ms[x].top();
        ms[x].pop();
    }
    while(ms[y].size() < w[y]) {
        ms[y].push(s[y].top());
        ans += s[y].top();
        s[y].pop();
    }
    while(!ms[y].empty() && !s[y].empty() && ms[y].top() < s[y].top()) {
        ms[y].push(s[y].top());
        ans += s[y].top();
        s[y].pop();
        s[y].push(ms[y].top());
        ans -= ms[y].top();
        ms[y].pop();
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n + m; ++i) par[i] = i, sz[i] = 1;
    vector<pair<int,int>> a;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back({x, 1});
    }
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.push_back({x, 0});
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n + m; ++i) {
        if(a[i].second == 1) {
            w[i] = 1;
            ans += a[i].first;
            ms[i].push(a[i].first);
        } else {
            s[i].push(a[i].first);
        }
    }
    vector<pair<int,int>> es;
    for(int i = 1; i < n + m; ++i) {
        es.push_back({a[i].first - a[i - 1].first, i - 1});
    }
    sort(es.begin(), es.end());
    vector<pair<int,int>> qry(q);
    for(int i = 0; i < q; ++i) {
        cin >> qry[i].first;
        qry[i].second = i;
    }
    sort(qry.begin(), qry.end());
    vector<ll> res(q);
    int j = 0;
    for(auto [k, id] : qry) {
        while(j < es.size() && es[j].first <= k) {
            merge(es[j].second, es[j].second + 1);
            j += 1;
        }
        res[id] = ans;
    }
    for(ll i : res) cout << i << '\n';
}
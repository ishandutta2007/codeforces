#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n, m;
vi color[maxn];
vector<pair<pair<int, int>, int> > edges;
int cnt[maxn];
map<pi, int> mp;

int p[2 * maxn];
int size[2 * maxn];
void init() {
    FOR(i, 0, 2 * maxn) {p[i] = i; size[i] = 1;}
}
int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}
bool issame(int u, int v) {
    return find(u) == find(v);
}
void join(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    p[y] = x; size[x] += size[y];
}

void solve() {
    ms(cnt, 0);
    scanf("%d%d", &n, &m);
    FOR(i, 0, m) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
        color[a].push_back(c); color[b].push_back(c);
        edges.push_back(make_pair(make_pair(a, b), c));
    }
    FOR(i, 0, n) {
        sort(color[i].begin(), color[i].end());
        color[i].erase(unique(color[i].begin(), color[i].end()), color[i].end());
        cnt[i + 1] = cnt[i] + sz(color[i]);
    }
    init();
    FOR(i, 0, sz(edges)) {
        int a = edges[i].first.first;
        int b = edges[i].first.second;
        int c = edges[i].second;
        int k = lower_bound(color[a].begin(), color[a].end(), c) - color[a].begin();
        int l = lower_bound(color[b].begin(), color[b].end(), c) - color[b].begin();
        join(cnt[a] + k, cnt[b] + l);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        if (sz(color[u]) > sz(color[v])) swap(u, v);
        int ans = 0;
        if (mp.count(make_pair(u, v))) ans = mp[make_pair(u, v)];
        else {
            FOR(i, 0, sz(color[u])) {
                int c = color[u][i];
                int k = lower_bound(color[v].begin(), color[v].end(), c) - color[v].begin();
                if (k != color[v].end() - color[v].begin() && issame(cnt[u] + i, cnt[v] + k)) ans++;
            }
            mp[make_pair(u, v)] = ans;
        }
        printf("%d\n", ans);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
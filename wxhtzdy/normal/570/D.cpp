#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

const int maxn=500005;

int val[maxn];
int lid[maxn], rid[maxn], tid;
int dep[maxn];
vi g[maxn], a[maxn];
vector<pi> qq[maxn];
set<int> s;
char str[maxn];

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    a[dep[u]].pb(u);
    lid[u] = ++tid;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    rid[u] = tid;
}

int bit[26][maxn];

void add(int c, int x, int y) {
    for (; x < maxn; x += x & -x) bit[c][x] += y;
}

int get(int c, int x) {
    int res = 0;
    for (; x; x -= x & -x) res += bit[c][x];
    return res;
}

void rem(int x) {
    for (int i : a[x]) {
        add(val[i], lid[i], -1);
    }
}

int ans[maxn];

void upd(int x) {
    for (int i : a[x]) {
        add(val[i], lid[i], 1);
    }
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[p].pb(i);
    }
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) val[i] = (str[i] - 'a');
    dfs(1, 0);
    for (int i = 0; i < q; i++) {
        int v, h;
        scanf("%d%d", &v, &h);
        qq[h].pb({v, i});
    }
    for (int i = 1; i <= n; i++) {
        rem(i - 1);
        upd(i);
        for (pi p : qq[i]) {
            int cnt = 0;
            for (int j = 0; j < 26; j++) {
                cnt += (get(j, rid[p.first]) - get(j, lid[p.first] - 1)) % 2;
            }
            ans[p.second] = (cnt <= 1 ? 1 : 0);
        }
    }
    for (int i = 0; i < q; i++) {
        if (ans[i] == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
#define ROW 5
#define N 1000005
#define IN 5
#define OR 10
#define AND 15
#define XOR 20
#define NOT 25
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
string b[2000500];
ll a[2000500], cur_ans[2005000], will_change[1005000];
vector<ll> g[1005000];
void dfs1(ll v) {
    if (b[v] == "IN") {
        cur_ans[v] = a[v];
        return;
    }
    for (int i = 0; i < g[v].size(); i++)
        dfs1(g[v][i]);
    if (b[v] == "NOT") {
        cur_ans[v] = 1 - cur_ans[g[v][0]];
        return;
    }
    ll x = cur_ans[g[v][0]], y = cur_ans[g[v][1]];
    if (b[v] == "OR") {
        cur_ans[v] = (x | y);
    } else
    if (b[v] == "AND") {
        cur_ans[v] = (x & y);
    } else if (b[v] == "XOR") {
        cur_ans[v] = (x ^ y);
    }
}
void dfs(ll v) {
    if (b[v] == "IN") {
        will_change[v] = 1;
        return;
    }
    if (b[v] == "XOR") {
        dfs(g[v][0]);
        dfs(g[v][1]);
    } else
    if (b[v] == "NOT") {
        dfs(g[v][0]);
    } else
    if (b[v] == "AND") {
        ll x = g[v][0];
        ll y = g[v][1];
        if (cur_ans[x] == 1 && cur_ans[y] == 1) {
            dfs(x);
            dfs(y);
        } else
        if (cur_ans[x] == 1 && cur_ans[y] == 0) {
            dfs(y);
        } else
        if (cur_ans[x] == 0 && cur_ans[y] == 1) {
            dfs(x);
        }
    } else {
        ll x = g[v][0];
        ll y = g[v][1];
        if (cur_ans[x] == 0 && cur_ans[y] == 0) {
            dfs(x);
            dfs(y);
        } else
        if (cur_ans[x] == 1 && cur_ans[y] == 0) {
            dfs(x);
        } else
        if (cur_ans[x] == 0 && cur_ans[y] == 1) {
            dfs(y);
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output3.txt", "w", stdout);
    //cin >> n >> m;
    //n = 1000, m = 1000;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "IN") {
            scanf("%d", &x);
            a[i] = x;
        } else if (s == "NOT") {
            scanf("%d", &x);
            g[i].push_back(x);
        } else {
            scanf("%d %d", &x, &y);
            g[i].push_back(x);
            g[i].push_back(y);
        }
        b[i] = s;
    }
    dfs1(1);
    /*for (int i = 1; i <= n; i++)
        cout << cur_ans[i];
    cout << endl;*/
    ll ans = cur_ans[1];
    dfs(1);
    /*for (int i = 1; i <= n; i++)
        if (b[i] == "IN")
        cout << will_change[i];
    cout << endl;*/
    for (int i = 1; i <= n; i++)
        if (b[i] == "IN")
            printf("%d", (ans^will_change[i]));
    return 0;
}
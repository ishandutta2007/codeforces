//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

int n, m;
vector<int> gr[N];
vector<int> who[N];
int a[N], b[N];
int ans[N];
int gt = 0;
int tin[N], tout[N];
int L[N], R[N], ptr = 0;
int cmin[4*N], mn[4*N];
int ex[4*N];

void build(int v, int l, int r){
    mn[v] = ex[v] = 0;
    cmin[v] = r - l + 1;
    if(l == r)ret;
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
}

void push(int v){
    if(!ex[v] || 2*v + 1 >= 4*N)ret;
    ex[2*v] += ex[v];
    ex[2*v+1] += ex[v];
    mn[2*v] += ex[v];
    mn[2*v+1] += ex[v];
    ex[v] = 0;
}

void add(int v, int l, int r, int ul, int ur, int d){
    if(ul > ur)ret;
    push(v);
    if(l == ul && r == ur){
        ex[v] += d;
        mn[v] += d;
        ret;
    }
    int mid = (l + r)/2;
    add(2*v, l, mid, ul, min(ur, mid), d);
    add(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, d);
    mn[v] = min(mn[2*v], mn[2*v+1]);
    cmin[v] = 0;
    if(mn[v] == mn[2*v])cmin[v] += cmin[2*v];
    if(mn[v] == mn[2*v+1])cmin[v] += cmin[2*v+1];
}

void mark(int v, int p = -1){
    tin[v] = gt++;
    L[v] = ptr++;
    I(u, gr[v]){
        if(u != p)
            mark(u, v);
    }
    R[v] = ptr - 1;
    tout[v] = gt++;
}

bool is_pr(int v, int u){
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void dfs(int v, int p = -1){
    I(x, who[v]){
        add(1, 0, n - 1, L[a[x]], R[a[x]], 1);
        add(1, 0, n - 1, L[b[x]], R[b[x]], 1);
    }
    int z = mn[1] == 0 ? cmin[1] : 0;
    if(z == n)--z;
    ans[v] = n - 1 - z;
    I(u, gr[v]){
        if(u != p)
            dfs(u, v);
    }
    I(x, who[v]){
        add(1, 0, n - 1, L[a[x]], R[a[x]], -1);
        add(1, 0, n - 1, L[b[x]], R[b[x]], -1);
    }
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
    F(i, 0, n - 1){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    mark(0);
    build(1, 0, n - 1);
    F(i, 0, m){
        int v, u;
        cin >> v >> u;
        --v; --u;
        if(is_pr(v, u))u = v;
        if(is_pr(u, v))v = u;
        a[i] = v;
        b[i] = u;
        if(v == u)
            who[v].pb(i);
        else{
            who[v].pb(i);
            who[u].pb(i);
        }
    }
    dfs(0);
    F(i, 0, n)cout << ans[i] << ' ';
	return 0;
}
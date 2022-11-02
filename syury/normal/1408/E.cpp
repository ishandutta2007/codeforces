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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6 + 5;

struct edge{
    int v, u, w;
    bool operator < (const edge & e)const{
        return w < e.w;
    }
};

int n, m;
edge e[N];
int ptr = 0;
int A[N], B[N];
int p[N];

int get(int v){
    return v == p[v] ? v : p[v] = get(p[v]);
}

bool unite(int v, int u){
    v = get(v);
    u = get(u);
    if(v == u)
        return 0;
    p[v] = u;
    return 1;
}

void solve(){
    iota(p, p + N, 0);
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++)
        scanf("%d", A + i);
    for(int i = 0; i < n; i++)
        scanf("%d", B + i);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int s;
        scanf("%d", &s);
        for(int j = 0; j < s; j++){
            int x;
            scanf("%d", &x);
            ans += A[i] + B[x - 1];
            e[ptr++] = edge{i, x - 1 + m, A[i] + B[x - 1]};
        }
    }
    sort(e, e + ptr);
    reverse(e, e + ptr);
    for(int i = 0; i < ptr; i++){
        int v = e[i].v, u = e[i].u, w = e[i].w;
        if(unite(v, u))
            ans -= w;
    }
    printf("%lld\n", ans);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}
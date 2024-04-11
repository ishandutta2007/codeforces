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

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)3e3 + 3;
const int inf = 1e9;

int d[N][N];
int prv[N][N];
vector<int> gr[N];
int n, m, k;
vector<int> fb[N][N];
pii q[N*N+2];
int qh = 0, qt = 0;

signed main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    scanf("%d%d%d", &n, &m, &k);
    F(i, 0, m){
        int v, u;
        scanf("%d%d", &v, &u);
        --v; --u;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    F(i, 0, k){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x; --y; --z;
        fb[x][y].pb(z);
    }
    F(i, 0, n)sort(all(gr[i]));
    F(i, 0, n)F(j, 0, n){
        sort(all(fb[i][j]));
        d[i][j] = inf;
    }
    q[qt++] = {0, 0};
    d[0][0] = 0;
    prv[0][0] = -1;
    while(qh < qt){
        int p, v;
        tie(p, v) = q[qh++];
        int ptr = 0;
        I(u, gr[v]){
            while(ptr < (int)fb[p][v].size() && fb[p][v][ptr] < u)++ptr;
            if(ptr < (int)fb[p][v].size() && fb[p][v][ptr] == u)cont;
            if(d[v][u] > d[p][v] + 1){
                prv[v][u] = p;
                d[v][u] = d[p][v] + 1;
                q[qt++] = {v, u};
            }
        }
    }
    int v = 0;
    F(i, 0, n){
        if(d[i][n-1] < d[v][n - 1])v = i;
    }
    if(d[v][n-1] == inf){
        printf("-1");
        return 0;
    }
    printf("%d\n", d[v][n - 1]);
    vector<int> kek;
    kek.pb(n);
    int old = n - 1;
    while(1){
        kek.pb(v + 1);
        if(v == 0)break;
        int tmp = v;
        v = prv[v][old];
        old = tmp;
    }
    reverse(all(kek));
    I(x, kek)printf("%d ", x);
	return 0;
}
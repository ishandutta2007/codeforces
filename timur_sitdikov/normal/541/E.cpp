#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

vector<int> g[MAXN];

vector<int> vv;
int col[MAXN], dis[MAXN];

int dfs(int s, int cl){
    col[s] = cl;
    vv.pb(s);
    int i, to;
    for(i = 0; i < SZ(g[s]); i++){
        to = g[s][i];
        if (col[to] == cl){
            return 1;
        }
        if (!col[to]){
            if (dfs(to, 3 - cl)){
                return 1;
            }
        }
    }
    return 0;
}

queue<int> qq;

void bfs(int s){
    int i, to;
    dis[s] = 1;
    qq.push(s);
    while(!qq.empty()){
        s = qq.front();
        qq.pop();
        for(i = 0; i < SZ(g[s]); i++){
            to = g[s][i];
            if (!dis[to]){
                dis[to] = dis[s] + 1;
                qq.push(to);
            }
        }
    }
}

void solve(){
    int n, m, i, j, k, a, b;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = 0;
    for(i = 1; i <= n; i++){
        if (col[i]){
            continue;
        }
        vv.clear();
        if (dfs(i, 1)){
            printf("-1\n");
            return;
        }
        int cur = 0;
        for(j = 0; j < SZ(vv); j++){
            //printf("%d ", vv[j]);
            for(k = 0; k < SZ(vv); k++){
                dis[vv[k]] = 0;
            }
            bfs(vv[j]);
            for(k = 0; k < SZ(vv); k++){
                cur = max(cur, dis[vv[k]] - 1);
            }
        }
        ans += cur;
    }
    printf("%d\n", ans);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
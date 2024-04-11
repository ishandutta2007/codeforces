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
const ll INF = 1e16;
const int MAXN = 6e5 + 5;
const ll MOD = 1e9 + 7;

struct edge{
    int s, to, w;
    edge(){}
    edge(int _s, int _to, int _w){
        s = _s, to = _to, w = _w;
    }
} ee[MAXN];

vector<int> g[MAXN];
int n;
ll dis[MAXN];
set<pair<ll, int> > st;
int prv_e[MAXN];

void go(int s){
    int i, ind, to;
    ll cur_dis;
    REP(i, 1, n + 1){
        dis[i] = INF;
    }
    dis[s] = 0ll;
    REP(i, 1, n + 1){
        st.insert(mp(dis[i], i));
    }
    while(!st.empty()){
        s = st.begin()->second;
        st.erase(st.begin());
        REP(i, 0, SZ(g[s])){
            ind = g[s][i];
            to = ee[ind].to;
            cur_dis = dis[s] + ee[ind].w;
            if (cur_dis <= dis[to]){
                prv_e[to] = ind >> 1;
                st.erase(mp(dis[to], to));
                dis[to] = cur_dis;
                st.insert(mp(dis[to], to));
            }
        }
    }
}

void solve(){
    int m, a, b, w, i, s;
    scanf("%d%d", &n, &m);
    REP(i, 0, m){
        scanf("%d%d%d", &a, &b, &w);
        ee[2 * i] = edge(a, b, w);
        ee[2 * i + 1] = edge(b, a, w);
        g[a].pb(2 * i);
        g[b].pb(2 * i + 1);
    }
    scanf("%d", &s);
    go(s);
    ll ans = 0ll;
    REP(i, 1, n + 1){
        if (i != s){
            ans += ee[prv_e[i] * 2].w;
        }
    }
    //printf("%lld\n", ans);
    cout << ans << endl;
    REP(i, 1, n + 1){
        if (i != s){
            printf("%d ", prv_e[i] + 1);
        }
    }
    putchar('\n');
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
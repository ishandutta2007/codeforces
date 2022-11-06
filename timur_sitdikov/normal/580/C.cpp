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

int v[MAXN], cnt[MAXN], bad[MAXN], used[MAXN], m;

void go(int s){
    int i, to;
    used[s] = 1;
    cnt[s] += v[s];
    if (cnt[s] > m){
        bad[s] = 1;
    }
    REP(i, 0, SZ(g[s])){
        to = g[s][i];
        if (!used[to]){
            if (bad[s]){
                bad[to] = 1;
            }
            if (v[s]){
                cnt[to] = cnt[s];
            }
            go(to);
        }
    }
    //printf("%d %d %d\n", s, v[s], cnt[s]);
}

void solve(){
    int n, i, a, b;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    go(1);
    int ans = 0;
    for(i = 2; i <= n; i++){
        if (SZ(g[i]) == 1 && !bad[i]){
            ans++;
        }
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
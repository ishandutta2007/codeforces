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

int good[MAXN], cnt_good[MAXN];

void go(int s, int prv){
    int i;
    if (SZ(g[s]) > 2){
        cnt_good[s]++;
        return;
    }
    good[s] = 1;
    REP(i, 0, SZ(g[s])){
        int to = g[s][i];
        if (to != prv){
            go(to, s);
        }
    }
}

void solve(){
    int n, i, j, a, b, mx = 0;
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
        mx = max(mx, SZ(g[a]));
        mx = max(mx, SZ(g[b]));
    }
    if (mx <= 2){
        printf("Yes\n");
        return;
    }
    for(i = 1; i <= n; i++){
        if (SZ(g[i]) == 1){
            go(i, 0);
        }
    }
    for(i = 1; i <= n; i++){
        if (SZ(g[i]) == 3 && cnt_good[i] >= 2){
            //printf("%d\n", i);
            good[i] = 1;
        }
    }
    for(i = 1; i <= n; i++){
        int cnt_bad = 0;
        REP(j, 0, SZ(g[i])){
            int to = g[i][j];
            cnt_bad += 1 - good[to];
        }
        if (cnt_bad > 2){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
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
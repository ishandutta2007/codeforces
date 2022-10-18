#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; \
    pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define SZ(a) int(a.size())

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

int main(){
    StarBurstStream

    int n, K;
    cin >> n >> K;
    vector<int> D(n + 1, n);
    for(int i = 1; i <= K; i++) cin >> D[i];
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> g[i][j];
        }
    }

    vector<pii> e;
    ll ans = 0;
    for(int i = 1; i < n; i++) e.eb(mp(i, n)), ans += g[i][n];
    //mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    random_device rd;
    mt19937 rnd(rd());
    while(clock() < CLOCKS_PER_SEC * 5.9){
        int rmv = rnd() % SZ(e);
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1);
        for(int j = 0; j < SZ(e); j++){
            if(j == rmv) continue;
            adj[e[j].F].eb(e[j].S);
            adj[e[j].S].eb(e[j].F);
            deg[e[j].F]++;
            deg[e[j].S]++;
        }

        vector<int> c(n + 1, -1);
        for(int j = 1; j <= n; j++){
            if(c[j] != -1) continue;
            queue<int> q;
            q.push(j);
            c[j] = j;
            while(!q.empty()){
                int now = q.front();
                q.pop();
                for(int v : adj[now]){
                    if(c[v] != -1) continue;
                    c[v] = j;
                    q.push(v);
                }
            }
        }

        int u = -1, v = -1;
        do{
            u = rnd() % n + 1;
            v = rnd() % n + 1;
            if(u > v) swap(u, v);
        }
        while(c[u] == c[v] || deg[u] + 1 > D[u] || deg[v] + 1 > D[v]);


        bool ok = false;
        if(g[u][v] < g[e[rmv].F][e[rmv].S]) ok = true;
        else if(rnd() % 5000 == 0) ok = true;
        if(!ok) continue;

        /*cerr << "test\n";
        printv(e, cerr);
        cerr << "remove " << rmv << " , insert " << u << " " << v << "\n";*/

        e[rmv] = mp(u, v);
        ll tans = 0;
        for(pii i : e) tans += g[i.F][i.S];
        ans = min(tans, ans);
    }

    cout << ans << "\n";

    return 0;
}
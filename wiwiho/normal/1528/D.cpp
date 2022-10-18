
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
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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
const ll MAX = 1LL << 60;

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

const int N = 600;
vector<vector<ll>> g;
int n, m;
ll dis[N];
ll d[N];
bool ok[N];

int mod(int qq){
    return qq >= n ? qq - n : qq;
}

void relax(int s){

    ll now = dis[s] % n;
    fill(d, d + n, MAX);
    for(int i = 0; i < n; i++){
        d[mod(i + now)] = g[s][i];
    }

    ll mn = MAX;
    for(int i = 0; i < n; i++){
        mn = min(mn, - i + d[i]);
    }

    for(int i = 0; i < n; i++){
        mn = min(mn, - (n + i) + d[i]);
        dis[i] = min(dis[i], dis[s] + n + i + mn);
    }
}

void calc(int s){

    fill(dis, dis + n, MAX);
    fill(ok, ok + n, false);
    dis[s] = 0;

    for(int i = 0; i < n; i++){
        pll now = mp(MAX, -1);
        for(int j = 0; j < n; j++){
            if(!ok[j]) now = min(now, mp(dis[j], (ll)j));
        }
        ok[now.S] = true;
        relax(now.S);
    }
}

int main(){
    StarBurstStream

    cin >> n >> m;
//    n = m = 600;
    g.resize(n, vector<ll>(n, MAX));

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
//        u = i, v = (i + 1) % n, w = 1;
        g[u][v] = w;
    }

    for(int i = 0; i < n; i++){
        calc(i);
        for(int j = 0; j < n; j++){
            cout << dis[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
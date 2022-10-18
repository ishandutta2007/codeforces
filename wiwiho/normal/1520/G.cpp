
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

vector<vector<ll>> g;
int n, m;
ll w;

vector<pii> dir = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};

vector<vector<ll>> getdis(int sx, int sy){
    queue<pii> q;
    q.push(mp(sx, sy));
    vector<vector<ll>> dis(n + 2, vector<ll>(m + 2, -1));
    dis[sx][sy] = 0;
    while(!q.empty()){
        pii now = q.front();
        q.pop();
        for(pii d : dir){
            int nx = now.F + d.F, ny = now.S + d.S;
            if(g[nx][ny] == -1 || dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[now.F][now.S] + 1;
            q.push(mp(nx, ny));
        }
    }
    return dis;
}

int main(){
    StarBurstStream

    cin >> n >> m >> w;

    g.resize(n + 2, vector<ll>(m + 2, -1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> g[i][j];
    }

    vector<vector<ll>> ds = getdis(1, 1);
    vector<vector<ll>> dt = getdis(n, m);

    ll ans = ds[n][m] == -1 ? (1LL << 60) : ds[n][m] * w;
    ll mn1 = 1LL << 60;
    ll mn2 = 1LL << 60;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(ds[i][j] != -1 && g[i][j] > 0) mn1 = min(mn1, ds[i][j] * w + g[i][j]);
            if(dt[i][j] != -1 && g[i][j] > 0) mn2 = min(mn2, dt[i][j] * w + g[i][j]);
        }
    }
    ans = min(ans, mn1 + mn2);
    if(ans == (1LL << 60)) ans = -1;

    cout << ans << "\n";

    return 0;
}
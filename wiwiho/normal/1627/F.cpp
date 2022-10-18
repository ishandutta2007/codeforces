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

void solve(){
    
    int n, m;
    cin >> m >> n;

    auto trans = [&](int &x, int &y){
        x = n - 1 - x;
        y = n - 1 - y;
    };
    auto getid = [&](int x, int y){ return x * (n + 1) + y; };

    vector<vector<int>> gx(n + 1, vector<int>(n + 1));
    vector<vector<int>> gy(n + 1, vector<int>(n + 1));
    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if(x1 == x2){
            if(y1 > y2) swap(y1, y2);
            gy[x2][y2]++;
            trans(x1, y1); trans(x2, y2);
            if(y1 > y2) swap(y1, y2);
            gy[x2][y2]++;
        }
        else{
            if(x1 > x2) swap(x1, x2);
            gx[x2][y2]++;
            trans(x1, y1); trans(x2, y2);
            if(x1 > x2) swap(x1, x2);
            gx[x2][y2]++;
        }
    }

    vector<vector<pii>> g((n + 1) * (n + 1));
    auto addedge = [&](int u, int v, int w){
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    };
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i < n){
                addedge(getid(i, j), getid(i + 1, j), gy[i][j]);
            }
            if(j < n){
                addedge(getid(i, j), getid(i, j + 1), gx[i][j]);
            }
        }
    }

    /*cerr << "gx\n";
    for(int i = 0; i <= n; i++) printv(gx[i], cerr);
    cerr << "gy\n";
    for(int i = 0; i <= n; i++) printv(gy[i], cerr);*/

    std::priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dis((n + 1) * (n + 1), MAX);
    dis[getid(n / 2, n / 2)] = 0;
    pq.push(mp(0, getid(n / 2, n / 2)));
    
    while(!pq.empty()){
        int now = pq.top().S;
        int d = pq.top().F;
        pq.pop();
        if(d != dis[now]) continue;
        for(pii i : g[now]){
            if(d + i.S < dis[i.F]){
                dis[i.F] = d + i.S;
                pq.push(mp(d + i.S, i.F));
            }
        }
    }

    int ans = MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, dis[getid(i, 0)]);
        ans = min(ans, dis[getid(n, i)]);
    }
    cout << m - ans << "\n";

}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
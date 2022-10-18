//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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

int v, e, n, k;
vector<vector<ll>> dis;
vector<int> pos;

vector<vector<int>> g;
vector<int> mch;
vector<bool> vst;

bool dfs(int now){
    vst[now] = true;
    for(int i : g[now]){
        if(mch[i] == -1 || (!vst[mch[i]] && dfs(mch[i]))){
            mch[i] = now;
            return true;
        }
    }
    return false;
}

bool check(int t){

    g.clear();
    mch.clear();
    g.resize(n + 1);
    mch.resize(v + 1, -1);
    vst.clear();
    vst.resize(n + 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= v; j++){
            if(dis[pos[i]][j] <= t) g[i].eb(j);
        }
    }

//    cerr << "test " << t << "\n";
//    for(int i = 1; i <= n; i++){
//        cerr << i << "  ";
//        printv(g[i], cerr);
//    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        vst.clear();
        vst.resize(n + 1);
        if(dfs(i)) cnt++;
    }
//    cerr << t << " " << cnt << "\n";

    return cnt >= k;
}

int main(){
    StarBurstStream

    cin >> v >> e >> n >> k;

    dis.resize(v + 1, vector<ll>(v + 1, MAX));
    pos.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> pos[i];

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], (ll)w);
        dis[v][u] = min(dis[u][v], (ll)w);
    }

    for(int i = 1; i <= v; i++) dis[i][i] = 0;

    for(int k = 1; k <= v; k++){
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

//    for(int i = 1; i <= v; i++) printv(dis[i], cerr);

    int l = 0, r = 1731312;
    while(l < r){
        int m = (l + r) / 2;
        if(check(m)) r = m;
        else l = m + 1;
    }

    if(l == 1731312) l = -1;
    cout << l << "\n";

    return 0;
}
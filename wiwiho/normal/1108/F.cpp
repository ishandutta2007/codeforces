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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

vector<vector<pii>> g;

vector<int> dsu, in, out;
int ts = 0;

int findDSU(int a){
    if(dsu[a] == a) return a;
    dsu[a] = findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a, int b){
    a = findDSU(a); b = findDSU(b);
    dsu[a] = b;
}

vector<vector<int>> anc, mx;

void dfs(int now, int p, int w){
    in[now] = ts++;
    anc[now][0] = p;
    mx[now][0] = w;
    for(pii i : g[now]){
        if(i.F == p) continue;
        dfs(i.F, now, i.S);
    }
    out[now] = ts++;
}

bool isAnc(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a, int b){
    if(isAnc(a, b)) swap(a, b);
    int ans = 0;
    for(int i = 19; i >= 0; i--){
        if(isAnc(anc[a][i], b)) continue;
        ans = max(ans, mx[a][i]);
        a = anc[a][i];
    }
    ans = max(ans, mx[a][0]);
    a = anc[a][0];
    if(a == b) return ans;
    for(int i = 19; i >= 0; i--){
        if(isAnc(anc[b][i], a)) continue;
        ans = max(ans, mx[b][i]);
        b = anc[b][i];
    }
    ans = max(ans, mx[b][0]);
    b = anc[b][0];
//    cerr << a << " " << b << " " << ans << "\n";
    return ans;
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<pair<int, pii>> e(m);
    for(int i = 0; i < m; i++){
        cin >> e[i].S.F >> e[i].S.S >> e[i].F;
    }

    lsort(e);
    dsu.resize(n + 1);
    for(int i = 1; i <= n; i++) dsu[i] = i;
    g.resize(n + 1);

    vector<pair<int, pii>> r;
    for(int i = 0; i < m; i++){
        if(findDSU(e[i].S.F) == findDSU(e[i].S.S)) r.eb(e[i]);
        else{
//            cerr << e[i] << "\n";
            unionDSU(e[i].S.F, e[i].S.S);
            g[e[i].S.F].eb(mp(e[i].S.S, e[i].F));
            g[e[i].S.S].eb(mp(e[i].S.F, e[i].F));
        }
    }

    anc.resize(n + 1, vector<int>(20));
    mx.resize(n + 1, vector<int>(20));
    in.resize(n + 1);
    out.resize(n + 1);
    dfs(1, 1, 0);

    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[anc[j][i - 1]][i - 1]);
        }
    }

    int ans = 0;
    for(auto i : r){
//        cerr << "test " << i << "\n";
        if(lca(i.S.F, i.S.S) == i.F) ans++;
    }
    cout << ans << "\n";

    return 0;
}
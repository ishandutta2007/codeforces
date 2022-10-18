
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

vector<vector<int>> g, r;
vector<int> bccid;
vector<vector<int>> bcc;
vector<bool> vst;
vector<int> tmp;
int ts = 1;
vector<bool> ok;

void dfs(int now){
    ok[now] = true;
    for(int i : g[now]){
        if(ok[i]) continue;
        dfs(i);
    }
}

void dfs1(int now){
    vst[now] = true;
    for(int i : r[now]){
        if(vst[i] || !ok[i]) continue;
        dfs1(i);
    }
    tmp.eb(now);
}

void dfs2(int now, int id){
    bccid[now] = id;
    bcc[id].eb(now);
    for(int i : g[now]){
        if(bccid[i] != 0 || !ok[i]) continue;
        dfs2(i, id);
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n, m;
        cin >> n >> m;
        g.clear();
        r.clear();
        bccid.clear();
        bcc.clear();
        vst.clear();
        tmp.clear();
        ok.clear();
        g.resize(n + 1);
        r.resize(n + 1);
        bccid.resize(n + 1);
        bcc.resize(n + 1);
        vst.resize(n + 1);
        ok.resize(n + 1);
        ts = 1;
        vector<bool> cy(n + 1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            r[v].eb(u);
            if(u == v) cy[u] = true;
        }
//        printv(cy, cerr);

        dfs(1);
//        printv(ok, cerr);
        for(int i = 1; i <= n; i++){
            if(vst[i] || !ok[i]) continue;
            dfs1(i);
        }
//        printv(tmp, cerr);
        reverse(iter(tmp));
        for(int i : tmp){
            if(bccid[i] != 0) continue;
            dfs2(i, ts++);
        }

//        printv(bccid, cerr);

        vector<int> ans(n + 1);
        ans[ts - 1] = 1;
        for(int i = ts - 1; i >= 1; i--){
            ans[i] = min(ans[i], 2);
            if(bcc[i].size() > 1 || cy[bcc[i][0]]) ans[i] = -1;
            vector<int> to;
            for(int v : bcc[i]){
                for(int j : g[v]){
                    if(bccid[j] == i) continue;
                    to.eb(bccid[j]);
                }
            }
            lsort(to);
            uni(to);
//            cerr << "test " << i << "  ";
//            printv(to, cerr);
            for(int j : to){
                if(ans[i] >= 1 && ans[j] != -1) ans[j] += ans[i];
                else ans[j] = -1;
            }
        }
//        printv(ans, cerr);

        for(int i = 1; i <= n; i++){
            cout << ans[bccid[i]] << " ";
        }
        cout << "\n";

    }

    return 0;
}
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
#define iceil(a, b) (((a) + (b) - 1) / (b))
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

vector<vector<int>> g;
vector<set<int>> st;
vector<pii> toanc;
vector<int> single;
vector<int> cnt;

vector<vector<int>> anc;
vector<int> in, out;
int ts = 0;
void dfsanc(int now, int p){
    in[now] = ts++;
    anc[0][now] = p;
    for(int i : g[now]){
        if(i == p) continue;
        dfsanc(i, now);
    }
    out[now] = ts++;
}

bool isAnc(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

pii lca(int a, int b){
    if(isAnc(a, b)){
        for(int i = 19; i >= 0; i--){
            while(!isAnc(anc[i][b], a)) b = anc[i][b];
        }
        return mp(-1, b);
    }
    if(isAnc(b, a)){
        for(int i = 19; i >= 0; i--){
            while(!isAnc(anc[i][a], b)) a = anc[i][a];
        }
        return mp(-1, a);
    }

    for(int i = 19; i >= 0; i--){
        while(!isAnc(anc[i][a], b)) a = anc[i][a];
    }

    for(int i = 19; i >= 0; i--){
        while(!isAnc(anc[i][b], a)) b = anc[i][b];
    }
    if(a > b) swap(a, b);

    return mp(a, b);
}

ll ans = 0;

void dfs(int now, int p){
    map<pii, int> pc;
    vector<int> del;
    for(int i : g[now]){
        if(i == p) continue;

        dfs(i, now);

        if(st[now].size() < st[i].size()){
            st[now].swap(st[i]);
        }

        for(int j : st[i]){
            if(st[now].find(j) != st[now].end()){
                del.eb(j);
                if(toanc[j].F == -1) cnt[toanc[j].S]--;
                else{
                    cnt[toanc[j].F]--;
                    cnt[toanc[j].S]--;
                }
            }
            else st[now].insert(j);
        }
    }

    ans += (ll) single[now] * st[now].size() + (ll) single[now] * (single[now] - 1) / 2;

    ll total = st[now].size() - del.size();
//    cerr << "test " << now << "\n";
//    printv(st[now], cerr);
//    printv(del, cerr);
//    printv(cnt, cerr);
    ll tans = 0;
    for(int i : del){
        st[now].erase(i);
        if(toanc[i].F == -1){
            tans += total - cnt[toanc[i].S];
//            cerr << "del1 " << i << " " << toanc[i] << " " << total - cnt[toanc[i].S] << " " << total << " " << cnt[toanc[i].S] << "\n";
            cnt[toanc[i].S]++;
            total++;
        }
    }

    for(int i : del){
        if(toanc[i].F != -1){
            tans += total - cnt[toanc[i].F] - cnt[toanc[i].S] + pc[toanc[i]];
//            cerr << "del2 " << i << " " << toanc[i] << " " << total - cnt[toanc[i].F] - cnt[toanc[i].S] + pc[toanc[i]] << " "
//                    << total << " " << cnt[toanc[i].F] << " " << cnt[toanc[i].S] << " " << pc[toanc[i]] << "\n";
            cnt[toanc[i].F]++;
            cnt[toanc[i].S]++;
            pc[toanc[i]]++;
            total++;
        }
    }
    ans += tans;

    cnt[now] += st[now].size();
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    g.resize(n + 1);
    st.resize(n + 1);
    anc.resize(20, vector<int>(n + 1));
    in.resize(n + 1);
    out.resize(n + 1);
    single.resize(n + 1);
    cnt.resize(n + 1);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfsanc(1, 1);
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }

    int m;
    cin >> m;
    toanc.resize(m + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        if(u == v){
            single[u]++;
            continue;
        }
        st[u].insert(i);
        st[v].insert(i);
        toanc[i] = lca(u, v);
    }

    dfs(1, 1);

    cout << ans << "\n";

    return 0;
}
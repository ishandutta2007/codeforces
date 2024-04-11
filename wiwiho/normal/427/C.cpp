//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<vector<int>> g, r;
vector<vector<int>> scc;
vector<int> l;
vector<bool> vst;

void dfs(int now){
    vst[now] = true;
    for(int i : r[now]){
        if(vst[i]) continue;
        dfs(i);
    }
    l.eb(now);
}

void dfs2(int now){
    //cerr << now << "\n";
    vst[now] = true;
    scc.back().eb(now);
    for(int i : g[now]){
        if(vst[i]) continue;
        dfs2(i);
    }
}


int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];



    g.resize(n + 1);
    r.resize(n + 1);

    int m;
    cin >> m;
    for(int i =0 ; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        r[v].eb(u);
    }

    vst.resize(n + 1);
    for(int i = 1; i <= n; i++){
        if(!vst[i]) dfs(i);
    }
    //printv(l, cerr);
    reverse(iter(l));

    vst.clear();
    vst.resize(n + 1);

    for(int i = 0; i < n; i++){
        if(!vst[l[i]]){
            //cerr << "test " << i << "\n";
            scc.eb();
            dfs2(l[i]);
        }
    }

    ll ans = 0, cnt = 1;
    for(auto& i : scc){
        ll mn = MAX, c = 0;
        for(int j : i){
            if(p[j] < mn) mn = p[j], c = 1;
            else if(p[j] == mn) c++;
        }
        ans += mn;
        cnt = cnt * c % MOD;
    }
    cout << ans << " " << cnt << "\n";

    return 0;
}
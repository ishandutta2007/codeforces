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

vector<vector<int>> g;
vector<int> dpt, deg;
vector<vector<int>> c;
vector<bool> isd;

void dfs(int now, int p, int d){
    dpt[now] = d;
    deg[now] = g[now].size();
    c[p].eb(now);
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now, d + 1);
    }
}

vector<int> ansv;

void del(int now){
    if(isd[now]) return;
    ansv.eb(now);
    isd[now] = true;
    for(int i : c[now]){
        if(!isd[i]) del(i);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    g.resize(n + 1);
    dpt.resize(n + 1);
    deg.resize(n + 1);
    c.resize(n + 1);
    isd.resize(n + 1);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        if(p != 0){
            g[i].eb(p);
            g[p].eb(i);
        }
    }

    dfs(1, 1, 0);

    set<pii, greater<>> s;
    for(int i = 1; i <= n; i++){
        if(deg[i] % 2 == 0) s.insert(mp(dpt[i], i));
    }

    while(!s.empty()){
        int now = s.begin()->S;
        s.erase(s.begin());
        if(isd[now]) continue;

        for(int i : g[now]){
            if(isd[i]) continue;
            deg[i]--;
            if(deg[i] % 2) s.erase(mp(dpt[i], i));
            else s.insert(mp(dpt[i], i));
        }

        del(now);
    }

    bool ans = true;
    for(int i = 1; i <= n; i++){
        if(!isd[i]) ans = false;
    }

    if(ans){
        cout << "YES\n";
        for(int i : ansv) cout << i << "\n";
    }
    else cout << "NO\n";

    return 0;
}
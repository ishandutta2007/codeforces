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
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int n;
vector<vector<int>> g;
bool ok = true;

int dfs(int now, int p, int k, int dpt){
    vector<int> yes, no;
    for(int i : g[now]){
        if(i == p) continue;
        int tmp = dfs(i, now, k, dpt + 1);
        if(!ok) return -1;
//        cerr << now << " " << i << " " << k << " " << dpt << " " << tmp << " " << (tmp - dpt + 1 > k) << "\n";
        if(tmp - dpt + 1 > k) no.eb(tmp);
        else yes.eb(tmp);
    }
//    cerr << "test " << now << "  ";
//    printv(no, cerr);
    if(no.size() >= 2){
        ok = false;
        return -1;
    }
    if(!no.empty()) return no[0];
    if(yes.empty()) return dpt;
    return *min_element(iter(yes));
}

bool check(int k){
    ok = true;
    int tmp = dfs(1, 1, k, 0);
    return ok && tmp <= k;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        cin >> n;
        g.clear();
        g.resize(n + 1);

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        int l = 1, r = n;
        while(l < r){
            int m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m + 1;
        }
        cout << l << "\n";

    }

    return 0;
}
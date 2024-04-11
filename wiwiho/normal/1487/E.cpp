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

int main(){
    StarBurstStream

    vector<int> n(4);
    vector<vector<ll>> a(4);
    for(int i = 0; i < 4; i++){
        cin >> n[i];
        a[i].resize(n[i]);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n[i]; j++) cin >> a[i][j];
    }

    vector<vector<vector<int>>> g(4);
    for(int i = 1; i < 4; i++){
        int m;
        cin >> m;
        g[i].resize(n[i]);
        while(m--){
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[i][v].eb(u);
        }
    }

    for(int i = 1; i < 4; i++){
        multiset<ll> tmp;

        for(ll j : a[i - 1]) tmp.insert(j);

        for(int j = 0; j < n[i]; j++){
            for(int k : g[i][j]){
                tmp.erase(tmp.find(a[i - 1][k]));
            }
            if(tmp.empty()) a[i][j] = MAX;
            else a[i][j] += *tmp.begin();
            for(int k : g[i][j]){
                tmp.insert(a[i - 1][k]);
            }
        }
    }

    ll ans = *min_element(iter(a[3]));
    if(ans >= MAX) ans = -1;
    cout << ans << "\n";

    return 0;
}
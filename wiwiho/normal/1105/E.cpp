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

vector<ll> g;
map<ll, int> ans;

int calc(ll now){
//    cerr << bitset<20>(now) << "\n";
    if(now == 0) return 0;
    if(ans.find(now) != ans.end()) return ans[now];
    int lb = __lg(now & -now);
    ans[now] = max(calc(now & g[lb]) + 1, calc(now ^ (1LL << lb)));
//    cerr << bitset<20>(now) << " " << ans[now] << "\n";
    return ans[now];
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    map<string, int> id;
    int ts = 0;

    g.resize(m);

    set<int> now;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t == 1){
            for(int j : now){
                for(int k : now){
                    g[j] |= (1LL << k);
                }
            }
            now.clear();
            continue;
        }
        string name;
        cin >> name;
        if(id.find(name) == id.end()) id[name] = ts++;
        now.insert(id[name]);
    }
    for(int j : now){
        for(int k : now){
            g[j] |= (1LL << k);
        }
    }

    for(int i = 0; i < m; i++) g[i] ^= (1LL << m) - 1;
//    for(int i = 0; i < m; i++) cerr << bitset<20>(g[i]) << "\n";

    cout << calc((1LL << m) - 1) << "\n";

    return 0;
}
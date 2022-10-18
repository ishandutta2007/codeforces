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

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n, k;
        cin >> n >> k;

        vector<set<int>> g(n + 1);
        vector<set<int>> l(n + 1);

        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            //assert(u < g.size() && v < g.size());
            g[u].insert(v);
            g[v].insert(u);
        }
        
        if(k == 1){
            cout << n - 1 << "\n";
            continue;
        }

        for(int i = 1; i <= n; i++){
            //assert(i < g.size());
            if(g[i].size() == 1){
                int p = *g[i].begin();
                l[p].insert(i);
            }
        }

        set<pii, greater<>> s;
        for(int i = 1; i <= n; i++){
            //assert(i < l.size());
            if(!l[i].empty()) s.insert(mp(l[i].size(), i));
        }

        int ans = 0;

        while(!s.empty() && s.begin()->F >= k){
            int now = s.begin()->S;
            //assert(l[now].size() == s.begin()->F);
            //assert(now < g.size() && now < l.size());
            s.erase(s.begin());
            ans++;
            for(int i = 0; i < k; i++){
                g[now].erase(*l[now].begin());
                l[now].erase(l[now].begin());
            }
            if(g[now].size() == 1){
                int p = *g[now].begin();
                //assert(p < l.size());
                s.erase(mp(l[p].size(), p));
                l[p].insert(now);
                s.insert(mp(l[p].size(), p));
            }
            else{
                s.insert(mp(l[now].size(), now));
            }
        }
        cout << ans << "\n";

    }

    return 0;
}
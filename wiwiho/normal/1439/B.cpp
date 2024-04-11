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

    int T;
    cin >> T;
    while(T--){

        int n, m, k;
        cin >> n >> m >> k;

        vector<unordered_set<int>> g(n + 1);
        vector<int> deg(n + 1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
            deg[u]++; deg[v]++;
        }

        if(k >= 500){
            cout << "-1\n";
            continue;
        }

        set<pii> s;
        for(int i = 1; i <= n; i++) s.insert(mp(deg[i], i));

        vector<bool> d(n + 1);
        bool ok = false;
        while(!s.empty()){
            int v = s.begin()->S;
            s.erase(s.begin());

            if(deg[v] >= k){
                ok = true;
                cout << "1 " << s.size() + 1 << "\n";
                cout << v << " ";
                for(pii i : s) cout << i.S << " ";
                cout << "\n";
                break;
            }

            if(deg[v] == k - 1){
                vector<int> t;
                t.eb(v);
                for(int i : g[v]){
                    if(!d[i]) t.eb(i);
                }

                bool yes = true;
                for(int i : t){
                    for(int j : t){
                        if(i == j) continue;
                        if(g[i].find(j) == g[i].end()){
                            yes = false;
                        }
                    }
                }

                if(yes){
                    ok = true;
                    cout << "2\n";
                    printv(t, cout);
                    break;
                }
            }

            d[v] = true;
            for(int i : g[v]){
                if(d[i]) continue;
                s.erase(mp(deg[i], i));
                deg[i]--;
                s.insert(mp(deg[i], i));
                g[i].erase(v);
            }
        }

        if(!ok) cout << "-1\n";

    }

    return 0;
}
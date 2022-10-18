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

vector<vector<int>> g;
vector<int> dpt, pr;
vector<bool> inc;
ll c = -1;

void dfs(int now, int p, int d){
    dpt[now] = d;
    pr[now] = p;
    for(int i : g[now]){
        if(i == p) continue;
//        cerr << now << " " << i << " " << dpt[now] << " " << dpt[i] << "\n";
        if(dpt[i] != -1){
            if(dpt[i] < d){
                c = d - dpt[i] + 1;
                int tmp = now;
                inc[tmp] = true;
                while(true){
                    tmp = pr[tmp];
                    inc[tmp] = true;
                    if(tmp == i) break;
                }
            }
            continue;
        }
        dfs(i, now, d + 1);
    }
}

ll sz = 0;
void dfs2(int now, int p){
    sz++;
    for(int i : g[now]){
        if(i == p || inc[i]) continue;
        dfs2(i, now);
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        ll n;
        cin >> n;

        g.clear();
        g.resize(n + 1);
        dpt.clear();
        dpt.resize(n + 1, -1);
        pr.clear();
        pr.resize(n + 1);
        inc.clear();
        inc.resize(n + 1);
        c = -1;

        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }

        dfs(1, 1, 0);

        ll k = n - c;
        ll ans = n * (n - 1) / 2 + c * (c - 1) / 2 + k * (c - 1);
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            if(!inc[i]) continue;
            sz = 0;
            dfs2(i, i);
            sz--;
            ans += sz * sum;
            sum += sz;
        }

        cout << ans << "\n";

    }

    return 0;
}
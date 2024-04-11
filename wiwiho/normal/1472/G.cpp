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

        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n + 1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
        }

        vector<int> dis(n + 1, -1);
        dis[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i : g[now]){
                if(dis[i] != -1) continue;
                dis[i] = dis[now] + 1;
                q.push(i);
            }
        }
//        printv(dis, cerr);

        vector<pii> t;
        for(int i = 1; i <= n; i++) t.eb(mp(dis[i], i));
        gsort(t);

        vector<int> dp(n + 1);
        for(pii tmp : t){
            int now = tmp.S;
            dp[now] = dis[now];

            for(int i : g[now]){
                if(dis[i] <= dis[now]) dp[now] = min(dp[now], dis[i]);
                else dp[now] = min(dp[now], dp[i]);
            }
        }

        for(int i = 1; i <= n; i++) cout << dp[i] << " ";
        cout << "\n";

    }

    return 0;
}
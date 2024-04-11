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

vector<int> cnt;
vector<ll> e;
vector<vector<pll>> g;

void dfs(int now, int p, ll w){
    e[now] = w;
    if(g[now].size() == 1) cnt[now]++;
    for(pll i : g[now]){
        if(i.F == p) continue;
        dfs(i.F, now, i.S);
        cnt[now] += cnt[i.F];
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        ll s;
        cin >> n >> s;
        cnt.clear();
        e.clear();
        g.clear();
        cnt.resize(n + 1);
        e.resize(n + 1);
        g.resize(n + 1);

        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].eb(mp(v, w));
            g[v].eb(mp(u, w));
        }

        dfs(1, 1, 0);

        std::priority_queue<pll> pq;
        ll sum = 0;
        for(int i = 2; i <= n; i++){
            sum += e[i] * cnt[i];
            pq.push(mp((e[i] + 1) / 2 * cnt[i], i));
        }

        ll ans = 0;
        while(sum > s){
            pll now = pq.top();
//            cerr << sum << " " << now << "\n";
            pq.pop();
            sum -= now.F;
            e[now.S] /= 2;
            pq.push(mp((e[now.S] + 1) / 2 * cnt[now.S], now.S));
            ans++;
        }

        cout << ans << "\n";

    }

    return 0;
}
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

vector<vector<int>> g;
vector<int> pr, sz, dpt, cnt;
std::priority_queue<pii> pq;

void dfs(int now, int p, int d){
    pr[now] = p;
    dpt[now] = d;
    for(int i : g[now]){
        if(i == p) continue;
        dfs(i, now, d + 1);
        sz[now] += sz[i] + 1;
        cnt[now]++;
//        cerr << now << " " << i << " " << cnt[now] << "\n";
    }
    if(!cnt[now]) pq.push(mp(d, now));
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    g.resize(n + 1);
    sz.resize(n + 1);
    pr.resize(n + 1);
    cnt.resize(n + 1);
    dpt.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 1, 0);

//    printv(dpt,cerr);
//    printv(sz,cerr);
//    printv(cnt,cerr);
//    printv(pr,cerr);

    ll ans = 0;
    while(k--){
        int now = pq.top().S;
//        cerr << "test " << now << " " << pq.top().F << "\n";
        ans += pq.top().F;
        pq.pop();
        if(now == pr[now]) continue;
        now = pr[now];
        cnt[now]--;
//        cerr << now << " " << cnt[now] << "\n";
        if(!cnt[now]) pq.push(mp(dpt[now] - sz[now], now));
    }

    cout << ans << "\n";

    return 0;
}
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

void sp(int s, vector<vector<int>>& g, vector<int>& dis){
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i : g[now]){
            if(dis[i] != -1) continue;
            dis[i] = dis[now] + 1;
            q.push(i);
        }
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        vector<ll> p(m + 1);
        for(int i = 1; i <= m; i++){
            cin >> p[i];
        }
        lsort(p);
        for(int i = 2; i <= m; i++) p[i] += p[i - 1];

        vector<vector<int>> g(n + 1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].eb(v);
            g[v].eb(u);
        }
//        printv(p, cerr);

        vector<int> disa(n + 1, -1), disb(n + 1, -1), disc(n + 1,-1);
        sp(a, g, disa);
        sp(b, g, disb);
        sp(c, g, disc);
//        printv(disa, cerr);
//        printv(disb, cerr);
//        printv(disc, cerr);

        ll ans = (1LL << 60);
        for(int i = 1; i <= n; i++){
            if(disa[i] + disb[i] + disc[i] > m) continue;
            ll t = p[disa[i] + disb[i] + disc[i]] + p[disb[i]];
            ans = min(ans, t);
        }

        cout << ans << "\n";

    }

    return 0;
}
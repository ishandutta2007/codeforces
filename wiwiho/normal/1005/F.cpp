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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(mp(v, i));
        g[v].eb(mp(u, i));
    }

    vector<int> dis(n + 1, -1);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(pii i : g[now]){
            if(dis[i.F] != -1) continue;
            dis[i.F] = dis[now] + 1;
            q.push(i.F);
        }
    }

    vector<vector<int>> ans;
    ll tt = 1;
    for(int i = 2; i <= n; i++){
        ans.eb();
        for(pii j : g[i]){
            if(dis[j.F] != dis[i] - 1) continue;
            ans.back().eb(j.S);
        }
        if(tt < k) tt *= ans.back().size();
    }
//    for(auto& i : ans) printv(i, cerr);

    tt = min(tt, (ll)k);

    cout << tt << "\n";
    for(int i = 0; i < tt; i++){
        int now = i;
        string s(m, '0');
        for(int j = 0; j < ans.size(); j++){
            s[ans[j][now % ans[j].size()]] = '1';
            now /= ans[j].size();
        }
        cout << s << "\n";
    }

    return 0;
}
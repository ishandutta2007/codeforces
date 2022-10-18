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

map<int, int> rs;
map<int, vector<int>> e;

int calc(int l, int r, vector<pii> &p, int n, int id){
    if(rs.find(id) != rs.end()) return rs[id];
//    cerr << id << "\n";

    int now = 0, ans = 0;
    map<int, int> dp;
    for(auto& i : e){
        if(i.F < l || i.F > r) continue;
        for(int j : i.S){
            if(p[j].S > r || p[j] == mp(l, r)) continue;
            dp[p[j].S] = max(dp[p[j].S], now + calc(p[j].F, p[j].S, p, n, j) + 1);
            ans = max(ans, dp[p[j].S]);
        }
        now = max(now, dp[i.F]);
    }

    rs[id] = ans;
    return ans;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        vector<pii> p(n);
        for(int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
        rs.clear();
        e.clear();
        for(int i = 0; i < n; i++) e[p[i].F].eb(i), e[p[i].S];

        cout << calc(0, 200001, p, n, -1) << "\n";
//        printv(rs, cerr);

    }

    return 0;
}
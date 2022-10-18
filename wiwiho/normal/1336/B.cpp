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

ll solve(vector<ll>& r, vector<ll>& g, vector<ll>& b){
    ll ans = (1LL << 62);
    for(int x : g){
//        cerr << x << "\n";
        if(upper_bound(iter(r), x) == r.begin() || lower_bound(iter(b), x) == b.end()) continue;
        ll y = *prev(upper_bound(iter(r), x));
        ll z = *lower_bound(iter(b), x);
        ans = min(ans, (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z));
//        cerr << x << " " << y << " " << z << "\n";
    }
    return ans;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int nr, ng, nb;
        cin >> nr >> ng >> nb;

        vector<ll> r(nr), g(ng), b(nb);
        for(int i = 0; i < nr; i++) cin >> r[i];
        for(int i = 0; i < ng; i++) cin >> g[i];
        for(int i = 0; i < nb; i++) cin >> b[i];
        lsort(r); lsort(b); lsort(g);

        ll ans = min({solve(r, g, b), solve(r, b, g), solve(b, r, g), solve(b, g, r), solve(g, r, b), solve(g, b, r)});
        cout << ans << "\n";

    }

    return 0;
}
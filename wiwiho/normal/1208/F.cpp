
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

const int SZ = 21;

void add(array<int, 2>& arr, int v){
    for(int i = 0; i < 2; i++){
        if(v > arr[i]) swap(v, arr[i]);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<array<int, 2>> dp(1 << SZ, {-1, -1});

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(dp[((1 << SZ) - 1) - a[i]], i);
    }

    for(int i = 0; i < SZ; i++){
        for(int j = 0; j < (1 << SZ); j++){
            if(1 << i & j) for(int t : dp[j ^ (1 << i)]) add(dp[j], t);
        }
    }

//    for(int i = 0; i < (1 << SZ); i++){
//        cerr << "test " << bitset<SZ>(i) << "  ";
//        printv(dp[i], cerr);
//    }
    for(int i = 0; i < (1 << (SZ - 1)); i++) dp[i].swap(dp[((1 << SZ) - 1) - i]);

//    for(int i = 0; i < (1 << SZ); i++){
//        cerr << "test " << bitset<SZ>(i) << "  ";
//        printv(dp[i], cerr);
//    }

    int ans = 0;
    for(int i = 1; i <= n - 2; i++){
        int now = 0;
//        cerr << "tset " << i << "\n";
        for(int j = SZ - 1; j >= 0; j--){
            if(1 << j & a[i]) continue;
            int nxt = now | (1 << j);
//            cerr << "OAO " << j << " " << bitset<SZ>(nxt) << " " << (dp[nxt][1] != -1 && i < dp[nxt][1]) << " ";
//            printv(dp[nxt], cerr);
            if(dp[nxt][1] != -1 && i < dp[nxt][1]) now = nxt;
        }
        ans = max(ans, a[i] | now);
    }

    cout << ans << "\n";

    return 0;
}
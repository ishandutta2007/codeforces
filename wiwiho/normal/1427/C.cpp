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
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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

    int r, n;
    cin >> r >> n;

    vector<int> t(n + 1), x(n + 1), y(n + 1);
    x[0] = y[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }

    vector<ll> dp(n + 1, -MAX);
    vector<ll> mx(n + 1, -MAX);
    dp[0] = mx[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(t[i] - t[j] > r * 2){
                dp[i] = max(dp[i], mx[j] + 1);
                break;
            }
            if(abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[i] - t[j]){
//                cerr << i << " " << j << ' ' << dp[j] + 1 << " " << abs(x[j] - x[i]) + abs(y[j] - y[i]) << " " << t[i] - t[j] << "\n";
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx[i] = max(mx[i - 1], dp[i]);
    }
//    printv(dp, cerr);

    cout << *max_element(iter(dp)) << "\n";

    return 0;
}
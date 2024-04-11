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


int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<pii> x(n);
    for(int i = 0; i < n; i++){
        int mid, s;
        cin >> mid >> s;
        x[i] = mp(mid - s, mid + s);
    }

    vector<int> dp(m + 2);
    for(int i = m; i > 0; i--){
        dp[i] = m - i + 1;

        for(int j = 0; j < n; j++){
            int l = x[j].F, r = x[j].S;
            if(i >= l && i <= r){
                dp[i] = min(dp[i], dp[min(m + 1, r + 1)]);
                continue;
            }
            if(l < i) continue;
            dp[i] = min(dp[i], l - i + dp[min(m + 1, r + l - i + 1)]);
        }
    }
//    printv(dp, cout);

    cout << dp[1] << "\n";

    return 0;
}
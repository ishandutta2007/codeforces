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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, MAX)), v(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        v[i][i] = a[i];
    }

    for(int len = 1; len < n; len++){
        for(int l = 0; l + len < n; l++){
            int r = l + len;
            for(int i = l; i < r; i++){
                if(dp[l][i] == 1 && dp[i + 1][r] == 1 && v[l][i] == v[i + 1][r]){
                    dp[l][r] = 1;
                    v[l][r] = v[l][i] + 1;
                    break;
                }
                else{
                    dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
                }
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}
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

    int T;
    cin >> T;

    while(T--){
        
        int n, m;
        cin >> n >> m;

        vector<vector<ll>> a(n, vector<ll>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }

        ll ans = (1LL << 60);
        
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                
                vector<vector<ll>> dp(n, vector<ll>(m, -1));
                ll t = a[x][y] - (x + y);

                if(a[0][0] >= t) dp[0][0] = a[0][0] - t;

                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(i == 0 && j == 0) continue;
    
                        ll tt = t + i + j;
                        if(a[i][j] < tt) continue;

                        if(i - 1 >= 0 && dp[i - 1][j] != -1)
                            dp[i][j] = dp[i - 1][j] + a[i][j] - tt;
                        if(j - 1 >= 0 && dp[i][j - 1] != -1)
                            if(dp[i][j] == -1 || dp[i][j - 1] + a[i][j] - tt < dp[i][j])
                                dp[i][j] = dp[i][j - 1] + a[i][j] - tt;

                        //cerr << i << " " << j << " " << a[i][j] << " " << tt << " " << dp[i][j] << "\n";
                    }
                }

                if(dp[n - 1][m - 1] != -1) ans = min(ans, dp[n - 1][m - 1]); 
                //cerr << x << " " << y << " " << t << " " << dp[n-1][m-1] << "\n";
            }
        }

        cout << ans << "\n";

    }

    return 0;
}
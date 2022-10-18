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

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

void mod(ll &x){
    if(x >= MOD) x -= MOD;
}

void calc2(int n, vector<vector<ll>>& cnt){
    vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(3, vector<ll>(3))));
    vector<vector<vector<vector<ll>>>> dp2(n + 1, vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(3, vector<ll>(3))));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int c1 = (i == 1) + (j == 1);
            int c2 = (i == 2) + (j == 2);
            dp[c1][c2][i][j] += (i == 0 ? 24 : 1) * (j == 0 ? 24 : 1);
        }
    }

    for(int i = 3; i <= n; i++){
        fill(iter(dp2), vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(3, vector<ll>(3))));
//        cerr << i << "\n";
        for(int j = 0; j < i; j++){ //number of a
            for(int k = 0; j + k < i; k++){ //number of b
                for(int t1 = 0; t1 < 3; t1++){
                    for(int t2 = 0; t2 < 3; t2++){
                        //add a
                        if(t1 != 1){
                            dp2[j + 1][k][t2][1] += dp[j][k][t1][t2];
                            mod(dp2[j + 1][k][t2][1]);
                        }
                        //add b
                        if(t1 != 2){
                            dp2[j][k + 1][t2][2] += dp[j][k][t1][t2];
                            mod(dp2[j][k + 1][t2][2]);
                        }
                        //add other
                        if(t1 == 1 || t1 == 2){
                            dp2[j][k][t2][0] += 24 * dp[j][k][t1][t2];
                            dp2[j][k][t2][0] %= MOD;
                        }
                        else{
                            dp2[j][k][t2][0] += 23 * dp[j][k][t1][t2];
                            dp2[j][k][t2][0] %= MOD;
                        }
                    }
                }
            }
        }
        dp.swap(dp2);
    }
    for(int i = n; i >= 0; i--){
        for(int j = n; j >= 0; j--){
            for(int t1 = 0; t1 < 3; t1++){
                for(int t2 = 0; t2 < 3; t2++){
                    cnt[i][j] += dp[i][j][t1][t2];
                    mod(cnt[i][j]);
                }
            }
            cnt[i][j] += cnt[i][j + 1];
            mod(cnt[i][j]);
        }
        for(int j = 0; j <= n; j++){
            cnt[i][j] += cnt[i + 1][j];
            mod(cnt[i][j]);
        }
    }
}

void calc1(int n, vector<ll> &cnt){
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(2)));
    vector<vector<vector<ll>>> dp2(n + 1, vector<vector<ll>>(2, vector<ll>(2)));
    for(int t1 = 0; t1 < 2; t1++){
        for(int t2 = 0; t2 < 2; t2++){
            dp[!!t1 + !!t2][t1][t2] += (t1 == 0 ? 25 : 1) * (t2 == 0 ? 25 : 1);
        }
    }
    for(int i = 3; i <= n; i++){
        fill(iter(dp2), vector<vector<ll>>(2, vector<ll>(2)));
        for(int j = 0; j < i; j++){
            for(int t1 = 0; t1 < 2; t1++){
                for(int t2 = 0; t2 < 2; t2++){
                    //add a
                    if(t1 != 1){
                        dp2[j + 1][t2][1] += dp[j][t1][t2];
                        mod(dp2[j + 1][t2][1]);
                    }
                    if(t1 == 1){
                        dp2[j][t2][0] += 25 * dp[j][t1][t2];
                        dp2[j][t2][0] %= MOD;
                    }
                    else{
                        dp2[j][t2][0] += 24 * dp[j][t1][t2];
                        dp2[j][t2][0] %= MOD;
                    }
                }
            }
        }
        dp.swap(dp2);
    }

    for(int i = n; i >= 0; i--){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                cnt[i] += dp[i][j][k];
                mod(cnt[i]);
            }
        }
        cnt[i] += cnt[i + 1];
        mod(cnt[i]);
    }
}


int main(){
    StarBurstStream

    int n;
    cin >> n;
    vector<int> c(26);
    for(int i = 0; i < 26; i++) cin >> c[i];

    vector<ll> cnt1(n + 2);
    vector<vector<ll>> cnt2(n + 2, vector<ll>(n + 2));
    calc1(n, cnt1);
    calc2(n, cnt2);

    ll ans = 26 * 26;
    for(int i = 3; i <= n; i++){
        ans *= 25;
        ans %= MOD;
    }
//    printv(cnt1, cerr);

    for(int i = 0; i < 26; i++){
        ans -= cnt1[c[i] + 1];
        topos(ans);
//        cerr << ans << " " << cnt1[c[i] + 1] << "\n";
    }
    for(int i = 0; i < 26; i++){
        for(int j = i + 1; j < 26; j++){
            ans += cnt2[c[i] + 1][c[j] + 1];
            mod(ans);
//            cerr << ans << " " << cnt2[c[i] + 1][c[j] + 1] << "\n";
        }
    }
    cout << ans << "\n";

    return 0;
}
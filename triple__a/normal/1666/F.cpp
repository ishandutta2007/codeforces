#include <bits/stdc++.h>
using namespace std;

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
    cerr << " " << H;
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

const int mod = 998244353;
int T, n;
int a[5050];
int cnt[5050];
int fac[5050], facinv[5050];
int rev[5050];

int power(int q, int w) {
    int ret = 1;
    while(w) {
        if(w & 1) ret = 1ll * ret * q % mod;
        q = 1ll * q * q % mod;
        w >>= 1;
    }
    return ret;
}

void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    a[0] = -1;
    fac[0] = facinv[0] = rev[0] = 1;
    for (int i = 1; i <= 5000; i += 1){
        fac[i] = 1ll * fac[i - 1] * i % mod;
        facinv[i] = power(fac[i], mod - 2);
        rev[i] = power(i, mod - 2);
    }
    cin >> T;
    while(T--) {
        cin >> n;
        
        for (int i = 1; i <= n; i += 1){
            cin >> a[i];
            cnt[a[i]] += 1;
        }
        sort(a + 1, a + n + 1);
        vector<vector<int> > dp(n / 2 + 1, vector<int>(2, 0));
        dp[0][0] = 1;
        int tmp = 1;
        for (int i = 1; i <= n; i += 1) {
            if(a[i] == a[i - 1]) tmp += 1;
            else tmp = 1;
            vector<vector<int> > new_dp(n / 2 + 1, vector<int>(2, 0));
            for (int j = 0; j <= min(i, n / 2); j += 1) {
                // choose
                if(j + 1 <= n / 2 && n / 2 - (i - 1 - j) <= n / 2 - j - 1) {
                    if(a[i] != a[i - 1]) {
                        add(new_dp[j + 1][1], (dp[j][0] + dp[j][1]) % mod);
                    }
                }
                // not choose
                if(n / 2 - (i - 1 - j) <= n / 2 - j - (j != 0)) {
                    //debug(i, j);
                    int pos = n / 2 - j - (j != 0);
                    int cur = n / 2 - (i - 1 - j) - 1;
                    if(a[i] == a[i - 1]) {
                        add(new_dp[j][0], 1ll * dp[j][0] * (pos - cur) % mod * rev[tmp] % mod);
                        add(new_dp[j][1], 1ll * dp[j][1] * (pos - cur) % mod * rev[tmp - 1] % mod);
                    }
                    else {
                        add(new_dp[j][0], 1ll * (dp[j][0] + dp[j][1]) * (pos - cur) % mod);
                    }
                }
                
            }
            //debug(new_dp[0][0], new_dp[1][1]);
            swap(dp, new_dp);
        }
        
        int res = (dp[n / 2][0] + dp[n / 2][1]) % mod;
        cout << res << "\n";
        for (int i = 1; i <= n; i += 1){
            cnt[i] = 0;
        }

    }
    return 0;
}
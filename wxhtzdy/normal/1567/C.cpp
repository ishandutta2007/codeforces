#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define ll long long

using namespace std;

int dig[10];
ll dp[11][(1 << 11)];

void klir(){
    ff(i,0,10){
        ff(j,0,(1<<11)-1){
            dp[i][j] = 0;
        }
    }
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    klir();
    ff(i,0,n-1)dig[i] = s[i] - '0';
    dp[0][0] = dig[0] + 1;
    dp[0][1] = 9 - dig[0];
    ff(i,1,n-1){
        ff(mask,0,(1<<(i+1))-1){
            int j = mask & (~(1 << i));
            if(mask & (1 << i)){
                if(i > 1 && (mask & (1 << (i - 2)))){
                    dp[i][mask] = (10 - dig[i]) * dp[i - 1][j];
                }
                else{
                    dp[i][mask] = (9 - dig[i]) * dp[i - 1][j];
                }
            }
            else{
                if(i > 1 && (mask & (1 << (i - 2)))){
                    dp[i][mask] = dig[i] * dp[i - 1][j];
                }
                else{
                    dp[i][mask] = (dig[i] + 1) * dp[i - 1][j];
                }
            }
        }
    }
    ll ans = 0;
    ff(mask,0,(1<<n)-1){
        if(!(mask & (1 << (n - 1))) && !(mask & (1 << (n - 2)))){
            ans += dp[n - 1][mask];
        }
    }
    cout << ans - 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}
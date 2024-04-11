#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[101][101];
int n; ll k;
string s;
int main(){
    cin >> n >> k >> s;
    for(int j=1;j<=n;j++){
        int lastFreq[26];
        memset(lastFreq,-1,sizeof(lastFreq));
        for(int i=0;i<n;i++){
            int curr = s[i]-'a';
            if(lastFreq[curr]==-1){
                if(j==1) dp[j][i] = 1;
                else{
                    for(int x=i-1;x>=0;x--){
                        dp[j][i]+=dp[j-1][x];
                        dp[j][i] = min(k,dp[j][i]);
                    }
                }
            }
            else{
                if(j==1) dp[j][i] = 0;
                else{
                    for(int x=i-1;x>=lastFreq[curr];x--){
                        dp[j][i]+=dp[j-1][x];
                        dp[j][i] = min(k,dp[j][i]);
                    }
                }
            }
            lastFreq[curr] = i;
        }
    }
    ll ans =0 ;
    for(int j=n;j>=1;j--){
        for(int i=0;i<n;i++){
            if(k<dp[j][i]) {
                ans+=k*1LL*(n-j);
                k = 0;
            }
            else{
                k-=dp[j][i];
                ans+=dp[j][i]*1LL*(n-j);
            }
        }
    }
    if(k>0){
        --k;
        ans+=n;
    }
    if(k>0) cout << -1 << endl;
    else cout << ans << endl;

}
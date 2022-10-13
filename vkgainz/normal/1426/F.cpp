#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3][200001];
ll tpow[200001];
ll mod = 1000000007;
int main(){
    tpow[0] = 1;
    for(int i=1;i<=200000;i++){
        tpow[i] = tpow[i-1]*1LL*3%mod;
    }
    int n; 
    cin >> n;
    string s; cin >> s;
    int num =0;
    for(int i=1;i<=s.length();i++){
        for(int j=0;j<3;j++) dp[j][i] = dp[j][i-1];
        if(s[i-1]=='a'){
            dp[0][i]+=tpow[num];   
        }
        else if(s[i-1]=='b'){
            dp[1][i]+=dp[0][i-1];
        }
        else if(s[i-1]=='c'){
            dp[2][i]+=dp[1][i-1];
        }
        else{
            dp[0][i] = 3*1LL*dp[0][i-1]+tpow[num];
            dp[1][i] = 3*1LL*dp[1][i-1]+dp[0][i-1];
            dp[2][i] = 3*1LL*dp[2][i-1]+dp[1][i-1];
            ++num;
        }
        for(int j=0;j<3;j++) dp[j][i]%=mod;
    }
    if(dp[2][s.length()] <0) dp[2][s.length()]+=mod;
    cout << dp[2][s.length()] << endl;


}
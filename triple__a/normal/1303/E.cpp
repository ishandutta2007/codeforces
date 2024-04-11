#include<bits/stdc++.h>
using namespace std;

const int maxn=507;
int t,n,m;
string s1,s2;
int dp[maxn][maxn];
bool ck(){
    int i=0,l=0;
    while (i<s1.size()&&l<s2.size()){
        if (s1[i]==s2[l]) l++;
        i++;
    }
    return (l>=s2.size());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>s1>>s2;
        n=s1.size(), m=s2.size();
        if (ck()){
            cout<<"YES"<<endl;
            goto cont;
        }
        else{
            for (int i=1;i<m;++i){
                memset(dp,0x80,sizeof(dp));
                for (int j=0;j<=n;++j) dp[j][0]=0;
                for (int j=0;j<n;++j){
                    for (int k=0;k<=i;++k){
                        dp[j+1][k]=dp[j][k];
                    }
                    for (int k=0;k<=i;++k){
                        if (k<i&&s1[j]==s2[k]) dp[j+1][k+1]=max(dp[j+1][k+1],dp[j][k]);
                        if (dp[j][k]>=0&&i+dp[j][k]<m&&s1[j]==s2[i+dp[j][k]]) dp[j+1][k]=max(dp[j+1][k],dp[j][k]+1);
                    }
                }
                if (dp[n][i]>=m-i){
                    cout<<"YES"<<endl;
                    goto cont;
                }
            }
        }
        cout<<"NO"<<endl;
        cont:;
    }
}
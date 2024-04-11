#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,dp[N][26];
string s;
void Solve(int pos){
    int k=pos;
    string ans="";
    ans+=(char)(pos+'a');
    for(int i=n-2;i>=0;i--){
        pair<int,int> tmp;
        tmp.first=n+1;
        tmp.second=25;
        for(int j=0;j<26;j++){
            if(k==j)continue;
            if(dp[i][j]<tmp.first){
                tmp.first=dp[i][j];
                tmp.second=j;
            }
        }
        k=tmp.second;
        ans+=(char)(tmp.second+'a');
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
int main(){
    cin>>s;
    n=(int)s.length();
    if(n==1)return 0*printf("%c",s[0]);
    for(int i=0;i<26;i++){
        dp[0][i]=1;
        if((char)(i+'a')==s[0])dp[0][i]=0;
    }
    for(int i=1;i<n;i++){
        int pref[26],suf[26];
        pref[0]=dp[i-1][0],suf[25]=dp[i-1][25];
        for(int j=1;j<26;j++)pref[j]=min(dp[i-1][j],pref[j-1]);
        for(int j=24;j>=0;j--)suf[j]=min(dp[i-1][j],suf[j+1]);
        for(int j=0;j<26;j++){
            if(j==0)dp[i][j]=suf[j+1];
            else if(j==25)dp[i][j]=pref[j-1];
            else dp[i][j]=min(pref[j-1],suf[j+1]);
            dp[i][j]+=s[i]!=(j+'a');
        }
    }
    pair<int,int> ans;
    ans.first=n+1;
    ans.second=25;
    for(int i=0;i<26;i++){
        if(dp[n-1][i]<ans.first){
            ans.first=dp[n-1][i];
            ans.second=i;
        }
    }
    Solve(ans.second);
    return 0;
}
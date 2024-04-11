#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn=205;const int maxn1=205;
int dp[maxn1][maxn1][maxn];char pr[maxn1][maxn1][maxn];array<int,3> pr1[maxn1][maxn1][maxn];
int32_t main()
{
    string s,t;cin>>s>>t;
    int n=s.size();int m=t.size();
    s.push_back('$');t.push_back('$');
    for(int i=0;i<maxn;++i) for(int j=0;j<maxn;++j) for(int k=0;k<maxn;++k) {dp[i][j][k]=1e9;}
    dp[0][0][0]=1;
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            for(int k=0;k<maxn;++k)
            {
                if(dp[i][j][k]==1e9) continue;
                int i1=i;int j1=j;
                if(s[i1]==')') ++i1; if(t[j1]==')') ++j1;
                if(k>=1 && dp[i1][j1][k-1]>dp[i][j][k]+1) {dp[i1][j1][k-1]=dp[i][j][k]+1;pr[i1][j1][k-1]=')';pr1[i1][j1][k-1]={i,j,k};}
                i1=i;j1=j;
                if(s[i1]=='(') ++i1; if(t[j1]=='(') ++j1;
                if(dp[i1][j1][k+1]>dp[i][j][k]+1) {dp[i1][j1][k+1]=dp[i][j][k]+1;pr[i1][j1][k+1]='(';pr1[i1][j1][k+1]={i,j,k};}
            }
            for(int k=maxn-1;k>=0;--k)
            {
                if(dp[i][j][k]==1e9) continue;
                int i1=i;int j1=j;
                if(s[i1]==')') ++i1; if(t[j1]==')') ++j1;
                if(k>=1 && dp[i1][j1][k-1]>dp[i][j][k]+1) {dp[i1][j1][k-1]=dp[i][j][k]+1;pr[i1][j1][k-1]=')';pr1[i1][j1][k-1]={i,j,k};}
                i1=i;j1=j;
                if(s[i1]=='(') ++i1; if(t[j1]=='(') ++j1;
                if(dp[i1][j1][k+1]>dp[i][j][k]+1) {dp[i1][j1][k+1]=dp[i][j][k]+1;pr[i1][j1][k+1]='(';pr1[i1][j1][k+1]={i,j,k};}
            }
        }
    }
    int x=n;int y=m;int o=0;
    string ans;
    while(x || y || o)
    {
        ans.push_back(pr[x][y][o]);
        array<int,3> u=pr1[x][y][o];
        x=u[0];y=u[1];o=u[2];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
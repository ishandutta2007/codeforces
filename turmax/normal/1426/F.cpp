#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
int go(string s,string u)
{
    int dp[s.size()+1][3];
    dp[0][0]=0;dp[0][1]=0;dp[0][2]=0;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j) dp[i+1][j]=dp[i][j];
        if(s[i]==u[0])
        {
            dp[i+1][0]++;
        }
        if(s[i]==u[1])
        {
            dp[i+1][1]+=dp[i][0];
        }
        if(s[i]==u[2])
        {
            dp[i+1][2]+=dp[i][1];
        }
        for(int j=0;j<3;++j) dp[i+1][j]%=p;
    }
    return dp[n][2];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int z1=inv(3);int z2=inv(9);int z3=inv(27);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k=0;
    for(auto h:s) if(h=='?') ++k;
    int ans=go(s,"abc")+(go(s,"?bc")+go(s,"a?c")+go(s,"ab?"))*z1+(go(s,"??c")+go(s,"?b?")+go(s,"a??"))*z2+go(s,"???")*z3;
    ans%=p;
    ans*=po(3,k);
    ans%=p;
    cout<<ans;
    return 0;
}
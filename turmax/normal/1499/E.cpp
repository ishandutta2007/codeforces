#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=1e3+5;
int dp[maxn][maxn][27];
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
int inv(int x) {return po(x,p-2);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s,t;
    cin>>s>>t;
    int cnt1=0;int cnt2=0;
    for(int i=0;i<s.size();++i)
    {
        bool ok=true;
        for(int j=(i+1);j<=s.size();++j)
        {
            ++cnt1;
            if(j==s.size() || s[j]==s[j-1])
            {
                ok=false;
                break;
            }
        }
    }
    for(int i=0;i<t.size();++i)
    {
        bool ok=true;
        for(int j=(i+1);j<=t.size();++j)
        {
            ++cnt2;
            if(t[j]==t[j-1])
            {
                ok=false;
                break;
            }
        }
    }
    int sum=0;
    for(int i=0;i<=s.size();++i)
    {
        for(int j=0;j<=t.size();++j)
        {
            for(int k=0;k<=26;++k)
            {
            if(k==26) dp[i][j][k]++;
            sum+=dp[i][j][k];
            dp[i][j][k]%=p;
            sum%=p;
            if((i+1)<=s.size() && (s[i]-'a')!=k)
            {
                dp[i+1][j][s[i]-'a']+=dp[i][j][k];
            }
            if((j+1)<=t.size() && (t[j]-'a')!=k)
            {
                dp[i][j+1][t[j]-'a']+=dp[i][j][k];
            }
            }
        }
    }
    //cerr<<sum<<endl;
    //cerr<<cnt1<<" "<<cnt2<<endl;
    cout<<(((sum-(s.size()+1)*(t.size()+1)-cnt1*(t.size()+1)-cnt2*(s.size()+1))%p)+p)%p<<endl;
    //cerr<<(sum-26*s.size()*t.size()*27)/26<<endl;
    sum-=(s.size()*t.size()*27);
    //cout<<sum<<" sum "<<endl;
    sum%=p;sum+=p;sum%=p;
    sum*=inv(26);sum%=p;//sum*=inv(26);sum%=p;
    //cout<<sum;
    return 0;
}
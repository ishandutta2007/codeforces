#include <bits/stdc++.h>

using namespace std;
#define int long long
int dp[1005][55][55];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<1005;++i)
    {
        for(int j=0;j<55;++j)
        {
            for(int k=0;k<55;++k)
            {
                dp[i][j][k]=(-1e18);
            }
        }
    }
    string h;
    cin>>h;
    string s,t;
    cin>>s>>t;
    int n=h.size();
    int s1[s.size()+1][26];
    int t1[t.size()+1][26];
    for(int i=0;i<=s.size();++i)
    {
        for(int j=0;j<26;++j)
        {
        string h=s.substr(0,i);
        h+=('a'+j);
        for(int z=0;z<=min(s.size(),h.size());++z)
        {
            if(s.substr(0,z)==h.substr(h.size()-z,z))
            {
                s1[i][j]=z;
            }
        }
        }
    }
    //cout<<0<<" 0 "<<endl;
    for(int i=0;i<=t.size();++i)
    {
        for(int j=0;j<26;++j)
        {
        string h=t.substr(0,i);
        h+=('a'+j);
        for(int z=0;z<=min(t.size(),h.size());++z)
        {
            //cout<<z<<" z "<<t.size()<<" t.size() "<<h.size()<<" h.size() "<<endl;
            if(t.substr(0,z)==h.substr(h.size()-z,z))
            {
                t1[i][j]=z;
            }
        }
        }
    }
    //cout<<1<<" 1 "<<endl;
    for(int i=0;i<=s.size();++i)
    {
        for(int j=0;j<=t.size();++j)
        {
            dp[0][i][j]=(-1e18);
        }
    }
    dp[0][0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=s.size();++j)
        {
            for(int k=0;k<=t.size();++k)
            {
                if(h[i]=='*')
                {
                for(char u='a';u<='z';++u)
                {
                    int x1=s1[j][u-'a'];int x2=t1[k][u-'a'];
                    int ans1=dp[i][j][k];
                    if(x1==s.size()) ++ans1;
                    if(x2==t.size()) --ans1;
                    dp[i+1][x1][x2]=max(dp[i+1][x1][x2],ans1);
                }
                }
                else
                {
                char u=h[i];
                //cout<<u<<" u "<<endl;
                int x1=s1[j][u-'a'];int x2=t1[k][u-'a'];
                int ans1=dp[i][j][k];
                if(x1==s.size()) ++ans1;//cout<<"plus "<<endl;}
                if(x2==t.size()) --ans1;//cout<<"minus "<<endl;}
                //cout<<ans1<<" ans1 "<<endl;
                dp[i+1][x1][x2]=max(dp[i+1][x1][x2],ans1);
                }
            }
        }
    }
    int ma=(-1e18);
    for(int i=0;i<=s.size();++i)
    {
        for(int j=0;j<=t.size();++j)
        {
            ma=max(ma,dp[n][i][j]);
        }
    }
    cout<<ma;
    return 0;
}
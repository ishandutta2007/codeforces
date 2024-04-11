#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
string dp[502][2][26];
vector <int> pr[502][2][26];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        char opt[k];
        for(int i=0;i<k;++i)
        {
            opt[i]=min('a'+i,'a'+max(0,min(i-1,(i+1)%k)));
            //cout<<i<<" i "<<opt[i]<<" opt[i] "<<endl;
        }
        for(int i=0;i<=(n+1);++i) for(int j=0;j<2;++j) for(int k=0;k<26;++k) {pr[i][j][k]={-1,-1,-1};dp[i][j][k]="";}
        for(int i=n;i<=n;++i)
        {
            for(int j=1;j<=1;++j)
            {
                for(int k=0;k<26;++k)
                {
                    dp[i][j][k]=('a'+k);
                    pr[i][j][k]={-1,-1,-1};
                }
            }
        }
        for(int i=(n-1);i>=0;i--)
        {
            for(int j=0;j<2;++j)
            {
                for(int k=0;k<26;++k)
                {
                    if(j==0)
                    {
                        dp[i][j][k]=opt[s[i]-'a'];
                        pr[i][j][k]={i+1,j,k};
                        if((i+1)<n && opt[s[i+1]-'a']<dp[i][j][k][0] && s[i+1]=='a')
                        {
                            dp[i][j][k]=s[i+1];
                            pr[i][j][k]={i+2,1,opt[s[i]-'a']-'a'};
                        }
                        else if((i+1)<n && opt[s[i+1]-'a']<dp[i][j][k][0])
                        {
                            dp[i][j][k]=opt[s[i+1]-'a'];
                            pr[i][j][k]={i+2,1,s[i]-'a'};
                        }
                        if((i+2)<n && s[i+2]<dp[i][j][k][0])
                        {
                            dp[i][j][k]=s[i+2];
                            dp[i][j][k]+=opt[s[i]-'a'];
                            pr[i][j][k]={i+3,1,s[i+1]-'a'};
                        }
                        /*if((i+2)<n && s[i+2]==dp[i][j][k][0] && s[i]<dp[i][j][k][1])
                        {
                            dp[i][j][k]=s[i+2];
                            dp[i][j][k]+=s[i];
                            pr[i][j][k]={i+3,1,s[i+1]-'a'};
                        }*/
                        for(int k=1;k<26;++k)
                        {
                            dp[i][j][k]=dp[i][j][0];
                            pr[i][j][k]=pr[i][j][0];
                        }
                        break;
                    }
                    else
                    {
                        dp[i][j][k]=('a'+k);
                        pr[i][j][k]={i,0,0};
                        if(s[i]<('a'+k))
                        {
                            dp[i][j][k]=s[i];
                            pr[i][j][k]={i+1,j,k};
                        }
                        if((i+1)<n && s[i+1]<dp[i][j][k][0])
                        {
                            dp[i][j][k]=s[i+1];
                            dp[i][j][k]+=('a'+k);
                            pr[i][j][k]={i+2,j,s[i]-'a'};
                        }
                    }
                }
            }
        }
        if(s.size()>=5)
        {
        //cout<<dp[4][0][0]<<" dp "<<endl;
        //cout<<pr[4][0][0][0]<<' '<<pr[4][0][0][1]<<' '<<pr[4][0][0][2]<<" pr "<<endl;
        }
        string ans;
        vector <int> v={0,0,0};
        while(true)
        {
            ans+=dp[v[0]][v[1]][v[2]];
            v=pr[v[0]][v[1]][v[2]];
            if(v[0]==(-1))
            {
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
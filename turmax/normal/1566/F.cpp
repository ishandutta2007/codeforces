#include <bits/stdc++.h>

using namespace std;
#define int long long
int getz(vector <pair<int,int> > z,int x,int y)
{
    //for(auto l:z) cout<<l.first<<' '<<l.second<<endl;
    int ans=1e18;
    for(auto h:z) ans=min(ans,h.first*x+h.second*y);
    //cout<<ans<<" ans "<<endl;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        a.push_back(-1e18);a.push_back(1e18);
        sort(a.begin(),a.end());
        vector <pair <int,int> > v[n+2];
        for(int i=0;i<m;++i)
        {
            int l,r;
            cin>>l>>r;
            if((upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l))!=0)
            {
                continue;
            }
            v[lower_bound(a.begin(),a.end(),l)-a.begin()].push_back({l,r});
        }
        int dp[n+2][4];//(l,r,lr,rl)
        for(int i=0;i<4;++i) dp[0][i]=0;
        for(int i=1;i<=(n+1);++i)
        {
            if(v[i].empty())
            {
                int mi=1e18;
                for(int j=0;j<4;++j)
                {
                    mi=min(mi,dp[i-1][j]);
                }
                //cout<<mi<<" mi "<<endl;
                for(int j=0;j<4;++j) dp[i][j]=mi;
                continue;
            }
            vector <pair<int,int> > h=v[i];
            h.push_back({a[i-1],a[i-1]});
            h.push_back({a[i],a[i]});
            sort(h.begin(),h.end());
            int mi[h.size()];
            mi[h.size()-1]=a[i];
            for(int i=h.size()-2;i>=0;i--)
            {
                mi[i]=min(mi[i+1],h[i].second);
            }
            vector <pair<int,int> > z;
            for(int j=0;j<(h.size()-1);++j)
            {
                z.push_back({h[j].first-a[i-1],a[i]-mi[j+1]});
            }
            for(int k=0;k<4;++k) {dp[i-1][k]=min(dp[i-1][k],(int) 1e18);dp[i][k]=1e18;}
            for(int j=0;j<4;++j)
            {
                for(int k=0;k<4;++k)
                {
                    if(j==0)
                    {
                        if(k==1)
                        {
                            dp[i][k]=min(dp[i][k],(int) 1e18);
                            continue;
                        }
                        if(k==0)
                        {
                            int mi=1e18;
                            for(auto h:v[i]) mi=min(mi,h.second);
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+a[i]-mi);
                            continue;
                        }
                        if(k==2)
                        {
                            int mi=1e18;
                            for(auto h:v[i]) mi=min(mi,h.second);
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+2*a[i]-2*mi);
                            continue;
                        }
                        if(k==3)
                        {
                            int mi=1e18;
                            for(auto h:v[i]) mi=min(mi,h.second);
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+a[i]-mi);
                            continue;
                        }
                    }
                    if(j==1 || j==2)
                    {
                        if(k==1)
                        {
                            int ma=(-1e18);
                            for(auto h:v[i]) ma=max(ma,h.first);
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+ma-a[i-1]);
                        }
                        if(k==0 || k==3)
                        {
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+getz(z,1,1));
                        }
                        if(k==2)
                        {
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+getz(z,1,2));
                        }
                    }
                    if(j==3)
                    {
                        if(k==1)
                        {
                            int ma=(-1e18);
                            for(auto h:v[i]) ma=max(ma,h.first);
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+2*ma-2*a[i-1]);
                        }
                        if(k==0 || k==3)
                        {
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+getz(z,2,1));
                        }
                        if(k==2)
                        {
                            dp[i][k]=min(dp[i][k],dp[i-1][j]+getz(z,2,2));
                        }
                    }
                }
            }
            //for(int k=0;k<4;++k) cout<<i<<" i "<<k<<" k "<<dp[i][k]<<endl;
        }
        int ans=1e18;
        ans=min(ans,dp[n+1][0]);ans=min(ans,dp[n+1][1]);ans=min(ans,dp[n+1][2]);ans=min(ans,dp[n+1][3]);
        cout<<ans<<'\n';
    }
    return 0;
}
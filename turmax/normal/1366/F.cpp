#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e3+5;
vector <pair<int,pair<int,int> > > b;
vector <pair<int32_t,pair<int32_t,int32_t> > > mom;
int dp[maxn+1][maxn+1];
int go(pair <int,int> a,pair <int,int> b)
{
    int u=b.second+a.second;
    int v=b.first-a.first+1;
    if(u%2==0)
    {
        return (((u/2)%p)*(v%p)-b.second)%p;
    }
    else
    {
        return (((v/2)%p)*(u%p)-b.second)%p;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        b.push_back({w,{x,y}});
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=maxn;++j)
        dp[i][j]=-1e18;
    }
    dp[0][0]=0;
    for(int i=0;i<maxn;++i)
    {
        for(int j=0;j<m;++j)
        {
            pair <int,pair<int,int> > z=b[j];
            int x=z.second.first;int y=z.second.second;int w=z.first;
            dp[x][i+1]=max(dp[x][i+1],w+dp[y][i]);
            dp[y][i+1]=max(dp[y][i+1],w+dp[x][i]);
        }
    }
    int sum=0;
    for(int i=0;i<=min(maxn-1,q);++i)
    {
        int ma=(-1e18);
        for(int j=0;j<n;++j)
        {
            ma=max(ma,dp[j][i]);
        }
        sum+=ma;
        sum%=p;
    }
    if(q<maxn)
    {
        cout<<sum;
        return 0;
    }
    vector <pair<int,int> > a;
    for(int i=0;i<m;++i)
    {
        int x=b[i].second.first;int y=b[i].second.second;
        int o=max(dp[x][maxn-1],dp[y][maxn-1]);
        int z=b[i].first;
        o-=(maxn-1)*z;
        a.push_back({z,o});
    }
    for(int i=0;i<m;++i)
    {
        mom.push_back({maxn,{i,i}});
    }
    for(int i=0;i<m;++i)
    {
        mom.push_back({q+1,{i,i}});
    }
    mom.push_back({1e9+5,{0,0}});
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<i;++j)
        {
            if((a[i].first-a[j].first)*(a[i].second-a[j].second)>=0)
            {
                continue;
            }
            else
            {
                int h=(a[i].second-a[j].second)/(a[j].first-a[i].first);
                if(h>=(maxn-1))
                {
                mom.push_back({h,{i,j}});
                mom.push_back({h+1,{i,j}});
                }
            }
        }
    }
    int ans=(-1e18);
    int l=0;
    sort(mom.begin(),mom.end());
    vector <pair<int,int> > v(mom.size());
    for(int i=0;i<mom.size();++i)
    {
        if(mom[i].first<maxn)
        {
            continue;
        }
        //cout<<l<<" l "<<endl;
        //cout<<mom[i].first<<" first "<<endl;
        int x=mom[i].first;
        ans=a[l].first*x+a[l].second;
        int l1=mom[i].second.first;int l2=mom[i].second.second;
        if((a[l1].first*x+a[l1].second)>ans)
        {
            ans=a[l1].first*x+a[l1].second;
            l=l1;
        }
        if((a[l2].first*x+a[l2].second)>ans)
        {
            ans=a[l2].first*x+a[l2].second;
            l=l2;
        }
        if(v.empty() || v[v.size()-1].first!=x)
        v.push_back({x,ans});
        else
        {
            v[v.size()-1].second=max(v[v.size()-1].second,ans);
        }
    }
    mom.clear();
    //cout<<l<<" l "<<endl;
    for(int i=0;i<v.size();++i)
    {
        if(v[i].first<maxn)
        {
            continue;
        }
        //cout<<v[i].first<<" first "<<endl;
        //cout<<v[i].second<<" second "<<endl;
        if(v[i+1].first==(1e9+5))
        {
            cout<<sum;
            return 0;
        }
        else
        {
            sum+=go(v[i],v[i+1]);
            sum%=p;
            sum+=p;
            sum%=p;
        }
    }
    return 0;
}
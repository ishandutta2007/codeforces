#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
vector <int> ch[maxn];
int corn[maxn];
bool used[maxn];
int dp[maxn];
int b[maxn];
vector <pair<int,int> > z;
vector <pair<int,int> > v;
vector <pair<int,int> > v1;
void dfs(int x)
{
    z.push_back({corn[x],x});
    used[x]=true;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            ch[x].push_back(v);
            dfs(v);
        }
    }
}
void go(int x)
{
    //cout<<x<<" x "<<endl;
    dp[x]=0;
    for(auto z:ch[x])
    {
        int ans=0;
        for(auto l:v)
        {
            int o=l.first;
            //cout<<o<<" o "<<endl;
            if(o==(-1)) continue;
            ans=max(dp[o],dp[z]);
            ans+=abs(b[o]-b[z]);
            //if(x==7) {cout<<b[o]<<" b[o] "<<b[z]<<" b[z] "<<endl;cout<<abs(b[o]-b[z])<<" abs "<<endl;}
            //if(x==7) cout<<o<<" o "<<endl;
            dp[x]=max(dp[x],ans);
        }
    }
    vector <int> h={dp[x]-b[x],dp[x]+b[x],b[x],-b[x]};
    for(int i=0;i<4;++i)
    {
        if(h[i]>v1[i].second)
        {
            //cout<<x<<" tgfrde "<<endl;
            v1[i].second=h[i];
            v1[i].first=x;
        }
    }
    //cout<<x<<" x "<<dp[x]<<" dp[x] "<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        z.clear();
        v={{-1,-1e18},{-1,-1e18},{-1,-1e18},{-1,-1e18}};
        v1=v;
        for(int i=0;i<n;++i) {used[i]=false;a[i].clear();ch[i].clear();}
        for(int i=0;i<(n-1);++i)
        {
            int x;
            cin>>x;
            a[i+1].push_back(x-1);a[x-1].push_back(i+1);
        }
        b[0]=0;
        for(int i=0;i<(n-1);++i) cin>>b[i+1];
        corn[0]=0;
        dfs(0);
        sort(z.begin(),z.end());reverse(z.begin(),z.end());
        int curr=1e18;
        for(auto h:z)
        {
            if(h.first!=curr)
            {
                //cout<<" ygtfr "<<endl;
                curr=h.first;
                v=v1;
                v1={{-1,-1e18},{-1,-1e18},{-1,-1e18},{-1,-1e18}};
            }
            go(h.second);
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
int t[4*maxn];
void to(int node,int tl,int tr,int pos,int x)
{
    if(tr<=pos || tl>pos)
    {
        return;
    }
    if((tr-tl)==1)
    {
        t[node]=x;
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,x);to(2*node+2,tm,tr,pos,x);
    t[node]=max(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t[node];
    }
    if(tl>=r || tr<=l)
    {
        return -1e18;
    }
    int tm=(tl+tr)/2;
    return max(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int slv(vector <int> v)
{
    for(int i=0;i<v.size();++i) v[i]-=i;
    vector <pair<int,int> > z;
    map <pair<int,int>,int> u;
    for(int i=0;i<v.size();++i)
    {
        z.push_back({v[i],i});
    }
    sort(z.begin(),z.end());
    for(int i=0;i<z.size();++i)
    {
        u[z[i]]=i;
    }
    for(int i=0;i<v.size();++i)
    {
        v[i]=u[{v[i],i}];
    }
    if(v.back()<v[0])
    {
        cout<<(-1);
        exit(0);
    }
    int ans=v.size();
    int dp[v.size()];
    dp[0]=1;
    to(0,0,maxn,v[0],1);
    for(int i=1;i<v.size();++i)
    {
        dp[i]=get(0,0,maxn,0,v[i])+1;
        to(0,0,maxn,v[i],dp[i]);
    }
    for(int i=0;i<v.size();++i)
    {
        to(0,0,maxn,i,-1e18);
    }
    return (ans-dp[v.size()-1]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<4*maxn;++i) t[i]=(-1e18);
    int n,k;
    cin>>n>>k;
    int a[n];
    bool used[n];
    for(int i=0;i<n;++i) used[i]=false;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<k;++i)
    {
        int x;
        cin>>x;
        x--;
        used[x]=true;
    }
    vector <int> v;
    v.push_back(-1e18);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(used[i])
        {
            v.push_back(a[i]);
            ans+=slv(v);
            v.clear();
        }
        v.push_back(a[i]);
    }
    v.push_back(1e18);
    ans+=slv(v);
    cout<<ans;
    return 0;
}
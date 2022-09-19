#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
int t[4*maxn];int delay[4*maxn];
vector<int> a[maxn];int c[maxn];pair<int,int> u[maxn];bool used[maxn];vector<int> h[maxn];vector<int> v;vector<int> v1;
void dfs(int x)
{
    used[x]=true;
    if(x==0) {u[x]={0,-1};}
    h[u[x].first].push_back(x);
    for(int v:a[x])
    {
        if(!used[v])
        {
            if(c[v]<=c[u[x].first]) {u[v]={v,u[x].first};}
            else if(u[x].second==(-1) || c[v]<=c[u[x].second]) {u[v]={u[x].first,v};}
            else u[v]=u[x];
            dfs(v);
        }
    }
    used[x]=false;
}
void push(int node)
{
    delay[2*node+1]+=delay[node];delay[2*node+2]+=delay[node];t[2*node+1]+=delay[node];t[2*node+2]+=delay[node];delay[node]=0;
}
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r) {t[node]+=val;delay[node]+=val;return;}
    if(tl>=r || tr<=l) return;
    push(node);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
void mi(int x)
{
    int pos=upper_bound(v.begin(),v.end(),x)-v.begin();
    if(pos>0) to(0,0,maxn,0,pos+1,-1);
}
void pl(int x)
{
    int pos=upper_bound(v.begin(),v.end(),x)-v.begin();
    if(pos>0) to(0,0,maxn,0,pos+1,1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;++i) cin>>c[i];
    for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);}
    int k;cin>>k;
    for(int i=0;i<k;++i) {int x;cin>>x;v1.push_back(x);v.push_back(x);}
    sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    for(int x:v1) mi(x);
    dfs(0);
    vector<int> v2;
    for(int i=0;i<n;++i) {pl(c[u[i].first]);v2.push_back(c[u[i].first]);}
    if(t[0]>=0)
    {
        cout<<0;return 0;
    }
    sort(v2.begin(),v2.end());sort(v1.begin(),v1.end());reverse(v2.begin(),v2.end());reverse(v1.begin(),v1.end());
    int ma=(-1);
    for(int i=0;i<k;++i)
    {
        if(v1[i]>v2[i]) {ma=v1[i];break;}
    }
    int ans=2e9;
        for(int v=0;v<n;++v)
        {
            int x=(ma-c[v]);
            if(x<=0) continue; if(x>=ans) continue;
            for(int i:h[v])
            {
                assert(u[i].first==v);
                mi(c[v]);
                if(i!=0) pl(min(c[v]+x,c[u[i].second]));
                else pl(c[v]+x);
            }
            if(t[0]>=0)
            {
                ans=x;
            }
            for(int i:h[v])
            {
                pl(c[v]);
                if(i!=0) mi(min(c[v]+x,c[u[i].second]));
                else mi(c[v]+x);
            }
        }
    if(ans==2e9) {cout<<(-1);return 0;}
    cout<<ans;
    return 0;
}
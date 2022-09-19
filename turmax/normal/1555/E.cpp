#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int t[4*maxn];
int delay[4*maxn];
void push(int node,int tl,int tr)
{
    t[2*node+1]+=delay[node];delay[2*node+1]+=delay[node];
    t[2*node+2]+=delay[node];delay[2*node+2]+=delay[node];
    delay[node]=0;
}
void pl(int node,int tl,int tr,int l,int r)
{
    if(tl>=r || tr<=l) return;
    if(tl>=l && tr<=r)
    {
        t[node]++;
        delay[node]++;
        return;
    }
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    pl(2*node+1,tl,tm,l,r);pl(2*node+2,tm,tr,l,r);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
void mi(int node,int tl,int tr,int l,int r)
{
    if(tl>=r || tr<=l) return;
    if(tl>=l && tr<=r)
    {
        t[node]--;
        delay[node]--;
        return;
    }
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    mi(2*node+1,tl,tm,l,r);mi(2*node+2,tm,tr,l,r);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t[node];
    }
    if(tl>=r || tr<=l) return 1e18;
    int tm=(tl+tr)/2;
    return min(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pair <int,pair<int,int> > a[n];
    for(int i=0;i<n;++i) {cin>>a[i].second.first>>a[i].second.second>>a[i].first;}
    sort(a,a+n);
    int ans=1e9;int r;
    for(int i=0;i<n;++i) {pl(0,1,m,a[i].second.first,a[i].second.second);if(t[0]>0) {ans=a[i].first-a[0].first;r=(i+1);break;}}
    assert(t[0]>0);
    int curr=0;
    while(true)
    {
        mi(0,1,m,a[curr].second.first,a[curr].second.second);
        ++curr;
        if(curr==n) break;
        bool ok=1;
        while(t[0]==0)
        {
            if(r==n)
            {
                ok=0;
                break;
            }
            pl(0,1,m,a[r].second.first,a[r].second.second);
            ++r;
        }
        if(!ok) break;
        else ans=min(ans,a[r-1].first-a[curr].first);
    }
    cout<<ans;
    return 0;
}
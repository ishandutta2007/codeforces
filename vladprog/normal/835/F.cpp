#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

set<pii> g[N];
bool used[N];
vector<int> cycle,len;
int h[N],l[N],r[N];

int find_cycle(int v,int p)
{
    if(used[v])
        return v;
    used[v]=true;
    for(auto to:g[v])
        if(to.x!=p)
        {
            int res=find_cycle(to.x,v);
            if(res)
                return cycle.push_back(v),
                       len.push_back(to.y),
                       v==res?0:res;
        }
    return 0;
}

pii far(int v,int p)
{
    pii ans(0,v);
    for(auto to:g[v])
        if(to.x!=p)
        {
            pii res=far(to.x,v);
            res.x+=to.y;
            ans=max(ans,res);
        }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v,l;
        cin>>u>>v>>l;
        g[u].insert({v,l});
        g[v].insert({u,l});
    }
    find_cycle(1,0);
    #define del(x,y) g[x].erase(g[x].lower_bound(pii(y,0)))
    int k=cycle.size();
    for(int i=0;i<k;i++)
        del(cycle[i],cycle[(i+1)%k]),
        del(cycle[(i+1)%k],cycle[i]);
    int ans1=0,mx=0;
    for(int i=0;i<k;i++)
    {
        int v;
        tie(h[i],v)=far(cycle[i],0);
        ans1=max(ans1,far(v,0).x);
        if(h[i]>h[mx])
            mx=i;
    }
    for(int i=(mx+1)%k,j=mx;i!=mx;j=i,i=(i+1)%k)
        r[i]=r[j]+len[i];
    for(int i=0;i<k;i++)
        if(i!=mx)
            r[i]+=h[i];
    for(int i=(mx+1)%k,j=mx;i!=mx;j=i,i=(i+1)%k)
        r[i]=max(r[i],r[j]);
    for(int i=(mx-1+k)%k,j=mx;i!=mx;j=i,i=(i-1+k)%k)
        l[i]=l[j]+len[j];
    for(int i=0;i<k;i++)
        if(i!=mx)
            l[i]+=h[i];
    for(int i=(mx-1+k)%k,j=mx;i!=mx;j=i,i=(i-1+k)%k)
        l[i]=max(l[i],l[j]);
    int ans2=1e18;
    for(int i=0,j=k-1;i<k;j=i,i++)
        ans2=min(ans2,max({l[i]+r[j],l[i]+h[mx],h[mx]+r[j]}));
//    for(int i=0;i<k;i++)
//        cout<<i<<" -> "<<cycle[i]<<" "<<len[i]<<" "<<h[i]<<" "<<l[i]<<" "<<r[i]<<"\n";
//    cout<<ans1<<" "<<ans2<<"\n";
    cout<<max(ans1,ans2);
}
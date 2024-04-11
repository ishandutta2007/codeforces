#include <bits/stdc++.h>

using namespace std;
#define int long long
int neutral=-1e18;
vector <int> t;
vector <int> l;
vector <int> r;
void build(int currnode,int tl,int tr,int maxn)
{
    if(t.size()!=(4*maxn))
    {
        t.resize(4*maxn);
    }
    if(l.size()!=(4*maxn))
    {
        l.resize(4*maxn);
    }
    if(r.size()!=(4*maxn))
    {
        r.resize(4*maxn);
    }
    t[currnode]=neutral;
    l[currnode]=tl;
    r[currnode]=tr;
    if((tr-tl)!=1)
    {
        build(2*currnode+1,tl,(tl+tr)/2,maxn);
        build(2*currnode+2,(tl+tr)/2,tr,maxn);
    }
}
void to(int currnode,int x,int y)
{
    if(l[currnode]>x || r[currnode]<=x)
    {
        return;
    }
    if((r[currnode]-l[currnode])==1)
    {
        t[currnode]=y;
        return;
    }
    to(2*currnode+1,x,y);
    to(2*currnode+2,x,y);
    t[currnode]=max(t[2*currnode+1],t[2*currnode+2]);
}
int get(int currnode,int tl,int tr)
{
    if(l[currnode]>=tr || r[currnode]<=tl)
    {
        return neutral;
    }
    if(l[currnode]>=tl && r[currnode]<=tr)
    {
        return t[currnode];
    }
    return max(get(2*currnode+1,tl,tr),get(2*currnode+2,tl,tr));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cycle=0;cycle<t;++cycle)
    {
    int n,m;
    int ma=(-1);
    int ma1=(-1);
    cin>>n;
    vector <int> a(n);
    build(0,0,n,n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        ma1=max(ma1,a[i]);
        to(0,i,a[i]);
    }
    cin>>m;
    int x,y;
    vector <pair<int,int> > b(m);
    int u;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        b[i]={y,x};
        ma=max(ma,x);
    }
    sort(b.begin(),b.end());
    int d=(-1);
    for(int i=m-1;i>=0;i--)
    {
        b[i].second=max(b[i].second,d);
        d=b[i].second;
    }
    if(ma<ma1)
    {
        cout<<(-1)<<endl;
        continue;
    }
    vector <int> can(n);
    int low,up;
    int k;
    int s;
    vector <pair<int,int> >::iterator it;
    for(int i=0;i<n;++i)
    {
        low=i;
        up=n+1;
        while(true)
        {
            if((up-low)==1)
            {
                can[i]=low;
                break;
            }
            k=(low+up)/2;
            it=lower_bound(b.begin(),b.end(),make_pair(k-i,0LL));
            s=it-b.begin();
            if(s!=b.size() && get(0,i,k)<=b[s].second)
            {
                low=k;
            }
            else
            {
                up=k;
            }
        }
    }
    int z=0;
    int h=0;
    while(h!=n)
    {
        h=can[h];
        ++z;
    }
    cout<<z<<endl;
    }
    return 0;
}
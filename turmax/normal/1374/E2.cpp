#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int sum1[4*maxn];
int sum2[4*maxn];
vector <pair<int,int> > a[2][2];
int l[2][2];
void build(int node,int tl,int tr)
{
    sum1[node]=0;sum2[node]=0;
    if((tr-tl)==1)
    {
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node,tl,tm);build(2*node+2,tm,tr);
}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tr<=pos || tl>pos)
    {
        return;
    }
    else
    {
        sum1[node]+=val;sum2[node]+=(val*pos);
    }
    if((tr-tl)==1)
    {
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    sum1[node]=sum1[2*node+1]+sum1[2*node+2];
    sum2[node]=sum2[2*node+1]+sum2[2*node+2];
}
int get(int node,int tl,int tr,int val)
{
    if(val==0)
    {
        return 0;
    }
    if(sum1[node]<val)
    {
        return 1e18;
    }
    if((tr-tl)==1)
    {
        return val*tl;
    }
    int tm=(tl+tr)/2;
    if(sum1[2*node+1]>=val)
    {
        return get(2*node+1,tl,tm,val);
    }
    else
    {
        return get(2*node+2,tm,tr,val-sum1[2*node+1])+sum2[2*node+1];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    build(0,0,maxn);
    int n,m,k;
    cin>>n>>m>>k;
    vector <pair<int,int> > h;
    for(int i=0;i<n;++i)
    {
        int t,x,y;
        cin>>t>>x>>y;
        a[x][y].push_back({t,i});
        h.push_back({t,i});
        to(0,0,maxn,t,1);
    }
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            sort(a[i][j].begin(),a[i][j].end());
        }
    }
    vector <pair<pair<int,int>,pair<int,int> > > u2;
    for(int i=0;i<min(a[0][1].size(),a[1][0].size());++i)
    {
        u2.push_back({a[0][1][i],a[1][0][i]});
    }
    vector <pair<int,int> > u1;
    for(int i=0;i<a[1][1].size();++i)
    {
        u1.push_back(a[1][1][i]);
    }
    int sz1=u1.size();int sz2=u2.size();
    if((sz1+sz2)<k)
    {
        cout<<(-1);
        return 0;
    }
    if(sz1<k && (2*k-sz1)>m)
    {
        cout<<(-1);
        return 0;
    }
    //cout<<sz1<<" "<<sz2<<" sz1 sz2 "<<endl;
    int ans1=0;
    int z1=min(sz1,k);
    for(int i=0;i<z1;++i)
    {
        to(0,0,maxn,u1[i].first,-1);
        ans1+=u1[i].first;
    }
    int z2=(k-z1);
    for(int i=0;i<z2;++i)
    {
        to(0,0,maxn,u2[i].first.first,-1);
        to(0,0,maxn,u2[i].second.first,-1);
        ans1+=u2[i].first.first;ans1+=u2[i].second.first;
    }
    int ans=1e18;
    int l1=(-1);
    int l2=(-1);
    while(z1>=0 && z2<=min(a[0][1].size(),a[1][0].size()))
    {
        if((2*z2+z1)>m)
        {
            break;
        }
        //cout<<ans1<<" ans1 "<<endl;
        int x=(get(0,0,maxn,m-z1-2*z2)+ans1);
        if(x<ans)
        {
            ans=x;
            l1=z1;
            l2=z2;
        }
        if(z1==0 || z2==(min(a[0][1].size(),a[1][0].size())))
        {
            break;
        }
        to(0,0,maxn,u1[z1-1].first,1);
        ans1-=u1[z1-1].first;
        z1--;
        to(0,0,maxn,u2[z2].first.first,-1);
        to(0,0,maxn,u2[z2].second.first,-1);
        ans1+=u2[z2].first.first;ans1+=u2[z2].second.first;
        ++z2;
    }
    cout<<ans<<endl;
    vector <int> v;
    for(int i=0;i<l1;++i)
    {
        v.push_back(u1[i].second);
    }
    for(int i=0;i<l2;++i)
    {
        v.push_back(u2[i].first.second);
        v.push_back(u2[i].second.second);
    }
    bool used[n];
    for(int i=0;i<n;++i) used[i]=false;
    for(int i=0;i<v.size();++i) used[v[i]]=true;
    vector <pair<int,int> > g;
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            g.push_back(h[i]);
        }
    }
    sort(g.begin(),g.end());
    int l=0;
    while(v.size()<m)
    {
        v.push_back(g[l].second);
        ++l;
    }
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<' ';
    }
    return 0;
}
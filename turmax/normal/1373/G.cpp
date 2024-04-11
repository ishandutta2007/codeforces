#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
int t[4*maxn];
int delay[4*maxn];
void build(int node,int tl,int tr)
{
    t[node]=tr-2;
    if((tr-tl)==1)
    {
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
}
void push(int node)
{
    int x=delay[node];
    t[2*node+1]+=x;
    t[2*node+2]+=x;
    delay[2*node+1]+=x;
    delay[2*node+2]+=x;
    delay[node]=0;
}
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=r || tr<=l)
    {
        return;
    }
    if(tl>=l && tr<=r)
    {
        delay[node]+=val;
        t[node]+=val;
        return;
    }
    push(node);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
    t[node]=max(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=r || tr<=l)
    {
        return 0;
    }
    if(tl>=l && tr<=r)
    {
        return t[node];
    }
    push(node);
    int tm=(tl+tr)/2;
    return max(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>k>>m;
    build(0,0,maxn);
    set <pair<int,int> > u;
    int r=n;
    set <int> z;
    map <int,int> h;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        int l=abs(x-k)+y;
        //cout<<l<<" l "<<endl;
        if(!u.count({x,y})){
        to(0,0,maxn,0,l+1,1);u.insert({x,y});
        if(z.count(-l))
        {
            h[l]++;
        }
        else
        {
            z.insert(-l);
            h[l]=1;
        }
        }
        else
        {
        to(0,0,maxn,0,l+1,-1);u.erase({x,y});
        if(z.count(-l))
        {
            h[l]--;
            if(!h[l])
            {
                z.erase(-l);
            }
        }
        }
        r=max(-(*z.begin()),n);
        //cout<<r<<" r "<<endl;
        cout<<max(0LL,get(0,0,maxn,0,r+1)-n)<<endl;
    }
    return 0;
}
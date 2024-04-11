#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
int t1[4*maxn];
void to1(int node,int tl,int tr,int l,int r,int x)
{
    if(tl>=l && tr<=r)
    {
        t1[node]=max(t1[node],x);
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    to1(2*node+1,tl,tm,l,r,x);to1(2*node+2,tm,tr,l,r,x);
}
int get1(int node,int tl,int tr,int l,int r,int curr=(-1e18))
{
    if(tl>=l && tr<=r)
    {
        return t1[node];
    }
    if(tl>=r || tr<=l)
    {
        return curr;
    }
    int tm=(tl+tr)/2;
    curr=max(curr,t1[node]);
    return max(get1(2*node+1,tl,tm,l,r,curr),get1(2*node+2,tm,tr,l,r,curr));
}
int t2[4*maxn];
void to2(int node,int tl,int tr,int l,int r,int x)
{
    if(tl>=l && tr<=r)
    {
        t2[node]=min(t2[node],x);
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    to2(2*node+1,tl,tm,l,r,x);to2(2*node+2,tm,tr,l,r,x);
}
int get2(int node,int tl,int tr,int l,int r,int curr=1e18)
{
    if(tl>=l && tr<=r)
    {
        return t2[node];
    }
    if(tl>=r || tr<=l)
    {
        return curr;
    }
    int tm=(tl+tr)/2;
    curr=min(curr,t2[node]);
    return min(get2(2*node+1,tl,tm,l,r,curr),get2(2*node+2,tm,tr,l,r,curr));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<4*maxn;++i)
    {
        t1[i]=(-1e18);
        t2[i]=1e18;
    }
    int n,m,q;
    cin>>n>>m>>q;
    bool ans=true;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x%2==0)
        {
            //cout<<x<<" x "<<endl;
            to1(0,0,maxn,0,x,y);
        }
        else
        {
            //cout<<x<<" x "<<endl;
            to2(0,0,maxn,x,maxn,y);
        }
        if(x%2==0)
        {
            //cout<<x<<" x "<<endl;
            //cout<<get2(0,0,maxn,x,x+1)<<endl;
            if(get2(0,0,maxn,x,x+1)<y)
            {
                ans=false;
            }
        }
        else
        {
            //cout<<x<<" x "<<endl;
            //cout<<get1(0,0,maxn,x,x+1)<<endl;
            if(get1(0,0,maxn,x,x+1)>=y)
            {
                ans=false;
            }
        }
        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
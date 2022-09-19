#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
int t[4*maxn];
int a[maxn];
void pl(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos)
    {
        return;
    }
    t[node]++;
    if((tr-tl)==1)
    {
        return;
    }
    int tm=(tl+tr)/2;
    pl(2*node+1,tl,tm,pos);pl(2*node+2,tm,tr,pos);
}
void mi(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos)
    {
        return;
    }
    t[node]--;
    if((tr-tl)==1)
    {
        return;
    }
    int tm=(tl+tr)/2;
    mi(2*node+1,tl,tm,pos);mi(2*node+2,tm,tr,pos);
}
int fin(int node,int tl,int tr,int k)
{
    if((tr-tl)==1)
    {
        //cout<<t[node]<<" t[node] "<<endl;
        return tl;
    }
    int x=t[2*node+1];
    int tm=(tl+tr)/2;
    if(x>=k)
    {
        return fin(2*node+1,tl,tm,k);
    }
    else
    {
        return fin(2*node+2,tm,tr,k-x);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[x]++;
        pl(0,0,maxn,x);
    }
    while(q--)
    {
        int x;
        cin>>x;
        if(x>=0)
        {
            pl(0,0,maxn,x);
            a[x]++;
        }
        else
        {
            int u=fin(0,0,maxn,-x);
            //cout<<u<<" u "<<endl;
            a[u]--;
            mi(0,0,maxn,u);
        }
    }
    for(int i=0;i<=(n+5);++i)
    {
        if(a[i])
        {
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=(1<<18);
int t[4*maxn];
bool r[20];
bool ch[20];
bool r1[4*maxn];
bool ch1[4*maxn];
int m[4*maxn];
void rev(int k)
{
    r[k]^=1;
}
void sw(int k)
{
    ch[k+1]^=1;
}
void to(int node,int tl,int tr,int pos,int x)
{
    //cout<<tl<<" "<<tr<<" "<<pos<<" "<<x<<endl;
    if(tr<=pos || tl>pos)
    {
        return;
    }
    if((tr-tl)==1)
    {
        t[node]=x;
        return;
    }
    if(r[m[tr-tl]]^r1[node]==1)
    {
        ch1[node]^=1;
        r1[2*node+1]^=1;
        r1[2*node+2]^=1;
        r1[node]^=1;
    }
    int tm=(tl+tr)/2;
    if(ch[m[tr-tl]]^ch1[node]==0)
    {
        to(2*node+1,tl,tm,pos,x);to(2*node+2,tm,tr,pos,x);
    }
    else
    {
        to(2*node+2,tl,tm,pos,x);to(2*node+1,tm,tr,pos,x);
    }
    t[node]=t[2*node+1]+t[2*node+2];
}
int get(int node,int tl,int tr,int l,int r2)
{
    if(tr<=l || tl>=r2)
    {
        return 0;
    }
    if(tl>=l && tr<=r2)
    {
        return t[node];
    }
    if(r[m[tr-tl]]^r1[node]==1)
    {
        ch1[node]^=1;
        r1[2*node+1]^=1;
        r1[2*node+2]^=1;
        r1[node]^=1;
    }
    int tm=(tl+tr)/2;
    if(ch[m[tr-tl]]^ch1[node]==0)
    {
        return get(2*node+1,tl,tm,l,r2)+get(2*node+2,tm,tr,l,r2);
    }
    else
    {
        return get(2*node+2,tl,tm,l,r2)+get(2*node+1,tm,tr,l,r2);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<20;++i)
    {
        m[1<<i]=i;
    }
    int n,q;
    cin>>n>>q;
    for(int i=0;i<(1<<n);++i)
    {
        int x;
        cin>>x;
        to(0,0,maxn,i,x);
    }
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            int pos,x;
            cin>>pos>>x;
            pos--;
            to(0,0,maxn,pos,x);
        }
        else if(typ==2)
        {
            int k;
            cin>>k;
            rev(k);
        }
        else if(typ==3)
        {
            int k;
            cin>>k;
            sw(k);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            l--;
            cout<<get(0,0,maxn,l,r)<<endl;
        }
    }
    return 0;
}
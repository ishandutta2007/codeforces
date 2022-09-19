#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int pr[maxn];
const int p=(1e9+9);
int inv2=(p+1)/2;
int sq5=383008016;
int fi1=((1+sq5)*inv2)%p;
int fi2=(((1-sq5)*inv2)%p+p)%p;
int po(int a,int b)
{
    if(b<0) return po(a,p-1+b);
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int invsq5=inv(sq5);
int f(int x)
{
    return ((((po(fi1,x)-po(fi2,x))*invsq5)%p)+p)%p;
}
vector <int> t[4*maxn]; //(const,l1^i*c2,l2^i*c3)
vector <int> operator +(vector <int> v1,vector <int> v2)
{
    vector <int> v3(v1.size());
    for(int i=0;i<v3.size();++i)
    {
        v3[i]=(v1[i]+v2[i])%p;
    }
    return v3;
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        t[node]={pr[tl]%p,0,0};
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    t[node]={0,0,0};
}
void pl(int node,int tl,int tr,int l,int r,vector <int> val)
{
    if(tl>=l && tr<=r)
    {
        t[node]=t[node]+val;
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    pl(2*node+1,tl,tm,l,r,val);pl(2*node+2,tm,tr,l,r,val);
}
void pl(int l,int r)
{
    int sum=f(r-l+2)-1;
    sum%=p;sum+=p;sum%=p;
    pl(0,0,maxn,r,maxn,{sum,0,0});
    pl(0,0,maxn,l+1,r,{-1,(invsq5*po(fi1,-l+2))%p,p-(invsq5*po(fi2,-l+2))%p});
}
vector <int> get(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos) return {0,0,0};
    if((tr-tl)==1) return t[node];
    int tm=(tl+tr)/2;
    return t[node]+get(2*node+1,tl,tm,pos)+get(2*node+2,tm,tr,pos);
}
int get1(int i)
{
    vector <int> v=get(0,0,maxn,i);
    return (v[0]+v[1]*po(fi1,i)+v[2]*po(fi2,i))%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n];pr[0]=0;
    for(int i=0;i<n;++i) {cin>>a[i];pr[i+1]=pr[i]+a[i];}
    build(0,0,maxn);
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            int l,r;
            cin>>l>>r;
            l--;
            pl(l,r);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            l--;
            cout<<(((get1(r)-get1(l))%p)+p)%p<<endl;
        }
    }
    return 0;
}
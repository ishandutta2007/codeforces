#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int a[maxn];array<array<double,3>,3> t[4*maxn];
int x,y;
void go(int node)
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            t[node][i][j]=0;
            t[node][i][j]=max(t[node][i][j],t[2*node+1][i][0]+t[2*node+2][0][j]);
            t[node][i][j]=max(t[node][i][j],t[2*node+1][i][1]+t[2*node+2][0][j]);
            t[node][i][j]=max(t[node][i][j],t[2*node+1][i][0]+t[2*node+2][1][j]);
            t[node][i][j]=max(t[node][i][j],t[2*node+1][i][1]+t[2*node+2][1][j]);
            t[node][i][j]=max(t[node][i][j],t[2*node+1][i][2]+t[2*node+2][0][j]);
            t[node][i][j]=max(t[node][i][j],t[2*node+1][i][0]+t[2*node+2][2][j]);
        }
    }
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        t[node][0][1]=(-1e18);t[node][0][2]=(-1e18);t[node][1][0]=(-1e18);t[node][1][2]=(-1e18);t[node][2][0]=(-1e18);t[node][2][1]=(-1e18);
        t[node][0][0]=0;t[node][1][1]=(a[tl]*1.0/(x+y+0.0));t[node][2][2]=(a[tl]*1.0/(x+0.0));return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);go(node);
}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1) {a[pos]=val;t[node][0][1]=(-1e18);t[node][0][2]=(-1e18);t[node][1][0]=(-1e18);t[node][1][2]=(-1e18);t[node][2][0]=(-1e18);t[node][2][1]=(-1e18);t[node][0][0]=0;t[node][1][1]=(a[tl]*1.0/(x+y+0.0));t[node][2][2]=(a[tl]*1.0/(x+0.0));return;}
    int tm=(tl+tr)/2;to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);go(node);
}
array<array<double,3>,3> get(int node,int tl,int tr,int l,int r)
{
    if(tl>=r || tr<=l) {array<array<double,3>,3> a;a[0][0]=(-1);return a;}
    if(tl>=l && tr<=r) {return t[node];}
    int tm=(tl+tr)/2;
    array<array<double,3>,3> a1=get(2*node+1,tl,tm,l,r);array<array<double,3>,3> a2=get(2*node+2,tm,tr,l,r);
    if(a1[0][0]==(-1)) return a2; if(a2[0][0]==(-1)) return a1;
    array<array<double,3>,3> a;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            a[i][j]=0;
            a[i][j]=max(a[i][j],a1[i][0]+a2[0][j]);
            a[i][j]=max(a[i][j],a1[i][1]+a2[0][j]);
            a[i][j]=max(a[i][j],a1[i][0]+a2[1][j]);
            a[i][j]=max(a[i][j],a1[i][1]+a2[1][j]);
            a[i][j]=max(a[i][j],a1[i][2]+a2[0][j]);
            a[i][j]=max(a[i][j],a1[i][0]+a2[2][j]);
        }
    }
    return a;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    cin>>x>>y;if(x<y) swap(x,y);
    for(int i=0;i<n;++i) cin>>a[i];
    build(0,0,n);
    while(q--)
    {
        int typ;cin>>typ;
        if(typ==1)
        {
            int pos,x;cin>>pos>>x;--pos;a[pos]=x;to(0,0,n,pos,x);
        }
        else
        {
            int l,r;cin>>l>>r;--l;array<array<double,3>,3> ans=get(0,0,n,l,r);double res=0;for(int i=0;i<3;++i) for(int j=0;j<3;++j) res=max(res,ans[i][j]); cout<<setprecision(15)<<res<<'\n';
        }
    }
    return 0;
}
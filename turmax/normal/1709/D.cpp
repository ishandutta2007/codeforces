#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int a[maxn];int t[4*maxn];
void build(int node,int tl,int tr)
{
    if((tr-tl)==1)
    {
        t[node]=a[tl];return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return t[node];
    if(tl>=r || tr<=l) return 1e18;
    int tm=(tl+tr)/2;
    return min(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n;cin>>m>>n;for(int i=0;i<n;++i) {cin>>a[i];a[i]=(m-a[i]);}
    build(0,0,n);
    int q;cin>>q;
    while(q--)
    {
        int xs,ys,xf,yf,k;cin>>xs>>ys>>xf>>yf>>k;
        --ys;--yf;xs=(m+1-xs);xf=(m+1-xf);
        if(ys>yf) {swap(xs,xf);swap(ys,yf);}
        if(((xf-xs)%k)!=0 || ((yf-ys)%k)!=0) {puts("NO");continue;}
        int ans1=get(0,0,n,ys,yf+1);
        puts(ans1>=(xf-1)%k+1 ? "YES" : "NO");
    }
    return 0;
}
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
#define N 100010
int n,m,a[N],px[N],py[N],f[N*4];bool g[N*4];
vector<int> A[N],B[N];
void add(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R){f[p]=r-l-f[p];g[p]^=1;return;}
    int mid=(l+r)/2;
    if(g[p])
    {
        f[p*2+1]=mid-l-f[p*2+1],g[p*2+1]^=1;
        f[p*2+2]=r-mid-f[p*2+2],g[p*2+2]^=1;
        g[p]=0;
    }
    if(L<mid)add(p*2+1,l,mid,L,R);
    if(mid<R)add(p*2+2,mid,r,L,R);
    f[p]=f[p*2+1]+f[p*2+2];
}
void add(int l,int r)
{
    if(l>=r)return;
    add(0,0,n,l,r);
}
int ask(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return f[p];
    int mid=(l+r)/2;
    if(g[p])
    {
        f[p*2+1]=mid-l-f[p*2+1],g[p*2+1]^=1;
        f[p*2+2]=r-mid-f[p*2+2],g[p*2+2]^=1;
        g[p]=0;
    }
    int S=0;
    if(L<mid)S+=ask(p*2+1,l,mid,L,R);
    if(mid<R)S+=ask(p*2+2,mid,r,L,R);
    return S;
}
int ask(int l,int r)
{
    if(l>=r)return 0;
    return ask(0,0,n,l,r);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),
        px[i]=lower_bound(a,a+n,x)-a,
        py[i]=upper_bound(a,a+n,y)-a,
        A[px[i]].pb(i),A[py[i]].pb(i);
    ll S=(ll)n*(n-1)*(n-2)/3;
    for(int i=0;i<n;i++)
    {
        for(vector<int>::iterator j=A[i].begin();j!=A[i].end();j++)
            add(px[*j],py[*j]);
        for(vector<int>::iterator j=B[i].begin();j!=B[i].end();j++)
            add(px[*j],py[*j]);
        ll x=ask(0,i),y=ask(i+1,n);
        ll l=x+(n-i-1-y),w=i-x+y;
        S-=l*(l-1)/2,S-=w*(w-1)/2;
    }
    cout<<S/2<<endl;
    return 0;
}
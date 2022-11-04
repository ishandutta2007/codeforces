#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;


ll m[maxn];
ll v[maxn];
ll a[maxn],aa[maxn];
ll b[maxn],bb[maxn];
ll id[maxn];
ll L;

int main()
{
    sync;
    int n;
    cin>>n;
    ll da=0;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
        v[i]=m[i];
    }
    reverse(v+1,v+n+1);
    ll pos=1;
    a[0]=0ll;
    a[1]=m[1];
    b[1]=m[1];
    b[0]=0;
    ll p;
    id[1]=1ll;
    L=m[1];
    for(int i=2;i<=n;i++)
    {
        if(m[i]>=L)
        {
            a[i]=a[i-1]+m[i];
            if(m[i]>L)
            {
                pos++;
                b[pos]=m[i];
                id[pos]=i;
            }
            L=m[i];
            continue;
        }
        p=id[lower_bound(b+1,b+pos+1,m[i])-b];
        a[i]=1ll*a[p-1]+1ll*m[i]*(i-p+1);
//        cout<<i<<' '<<p<<' '<<a[i]<<endl;
        pos=lower_bound(b+1,b+pos+1,m[i])-b;
//        id[p]=i;
        b[pos]=m[i];
        L=m[i];
    }
    
    
    mm(id);
    pos=1;
    aa[0]=0ll;
    aa[1]=v[1];
    bb[1]=v[1];
    bb[0]=0ll;
    id[1]=1ll;
    L=v[1];
    for(int i=2;i<=n;i++)
    {
        if(v[i]>=L)
        {
            aa[i]=aa[i-1]+v[i];
            if(v[i]>L)
            {
                pos++;
                bb[pos]=v[i];
                id[pos]=i;
            }
            L=v[i];
            continue;
        }
        p=id[lower_bound(bb+1,bb+pos+1,v[i])-bb];
        aa[i]=1ll*aa[p-1]+1ll*v[i]*(i-p+1ll);
        pos=lower_bound(bb+1,bb+pos+1,v[i])-bb;
//        id[p]=i;
        bb[pos]=v[i];
        L=v[i];
    }
    
    for(int i=1;i<=n;i++)
    {
//        cout<<a[i]+aa[n-i+1]-m[i]<<' ';
        if(1ll*a[i]+1ll*aa[n-i+1]-1ll*m[i]>da)
        {
            pos=i;
            da=1ll*a[i]+1ll*aa[n-i+1]-1ll*m[i];
        }
    }
    
    v[pos]=m[pos];
    for(int i=pos-1;i>=1;i--)
    {
        v[i]=min(m[i],v[i+1]);
    }
    for(int i=pos+1;i<=n;i++)
    {
        v[i]=min(m[i],v[i-1]);
    }
    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
    cout<<endl;
    return 0;
}
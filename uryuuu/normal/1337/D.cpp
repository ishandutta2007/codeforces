#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn],b[maxn],c[maxn];

int main()
{
    int t,na,nb,nc;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&na,&nb,&nc);
        for(int i=1;i<=na;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=nb;i++)
        {
            scanf("%lld",&b[i]);
        }
        for(int i=1;i<=nc;i++)
        {
            scanf("%lld",&c[i]);
        }
        sort(a+1,a+na+1);
        sort(b+1,b+nb+1);
        sort(c+1,c+nc+1);
        ll zx=4e18;
        zx+=10ll;
        ll x;
        ll s;
        int pos1,pos2;
        ll q,w;
        for(int i=1;i<=na;i++)
        {
            x=a[i];
            pos1=upper_bound(b+1,b+nb+1,x)-b-1;
            pos2=lower_bound(c+1,c+nc+1,x)-c;
            if(pos1>=1&&pos1<=nb&&pos2>=1&&pos2<=nc)
            {
                q=1ll*x-b[pos1];
                w=1ll*c[pos2]-x;
                s=1ll*2ll*q*q+1ll*2ll*w*w+1ll*2ll*q*w;
                zx=min(s,zx);
            }
            pos1=upper_bound(c+1,c+nc+1,x)-c-1;
            pos2=lower_bound(b+1,b+nb+1,x)-b;
            if(pos1>=1&&pos1<=nc&&pos2>=1&&pos2<=nb)
            {
                q=1ll*x-c[pos1];
                w=1ll*b[pos2]-x;
                s=1ll*2ll*q*q+1ll*2ll*w*w+1ll*2ll*q*w;
                zx=min(s,zx);
            }
        }
        
        for(int i=1;i<=nb;i++)
        {
            x=b[i];
            pos1=upper_bound(a+1,a+na+1,x)-a-1;
            pos2=lower_bound(c+1,c+nc+1,x)-c;
            if(pos1>=1&&pos1<=na&&pos2>=1&&pos2<=nc)
            {
                q=1ll*x-a[pos1];
                w=1ll*c[pos2]-x;
                s=1ll*2ll*q*q+1ll*2ll*w*w+1ll*2ll*q*w;
                zx=min(s,zx);
            }
            pos1=upper_bound(c+1,c+nc+1,x)-c-1;
            pos2=lower_bound(a+1,a+na+1,x)-a;
            if(pos1>=1&&pos1<=nc&&pos2>=1&&pos2<=na)
            {
                q=1ll*x-c[pos1];
                w=1ll*a[pos2]-x;
                s=1ll*2ll*q*q+1ll*2ll*w*w+1ll*2ll*q*w;
                zx=min(s,zx);
            }
        }
        
        for(int i=1;i<=nc;i++)
        {
            x=c[i];
            pos1=upper_bound(b+1,b+nb+1,x)-b-1;
            pos2=lower_bound(a+1,a+na+1,x)-a;
            if(pos1>=1&&pos1<=nb&&pos2>=1&&pos2<=na)
            {
                q=1ll*x-b[pos1];
                w=1ll*a[pos2]-x;
                s=1ll*2ll*q*q+1ll*2ll*w*w+1ll*2ll*q*w;
                zx=min(s,zx);
            }
            pos1=upper_bound(a+1,a+na+1,x)-a-1;
            pos2=lower_bound(b+1,b+nb+1,x)-b;
            if(pos1>=1&&pos1<=na&&pos2>=1&&pos2<=nb)
            {
                q=1ll*x-a[pos1];
                w=1ll*b[pos2]-x;
                s=1ll*2ll*q*q+1ll*2ll*w*w+1ll*2ll*q*w;
                zx=min(s,zx);
            }
        }
        
        printf("%lld\n",zx);
    }
    
    return 0;
}
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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn];
ll b[65];
ll c[65];

int main()
{
//    sync;
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mm(b);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        ll d;
        int i,j;
        for(i=1;i<=n;i++)
        {
            d=a[i];
            for(j=0;j<=61;j++)
            {
                if(d%2ll)
                {
                    b[j]++;
                }
                d=1ll*d/2ll;
                if(d==0)
                    break;
            }
        }
        ll sum=0;
        ll x,y;
        ll s;
        ll pre=0ll;
        for(i=1;i<=n;i++)
        {
            d=a[i];
            for(j=0;j<=61;j++)
                c[j]=0;
            for(j=0;j<=61;j++)
            {
                if(d%2ll)
                {
                    c[j]++;
                }
                d=1ll*d/2ll;
                if(d==0)
                    break;
            }
            pre=0ll;
            for(int j=0;j<=61;j++)
            {
                x=(1ll<<j)%Mod;
                if(c[j])
                {
                    pre=(1ll*pre+1ll*b[j]*x%Mod)%Mod;
                }
            }
            for(int j=0;j<=61;j++)
            {
                x=(1ll<<j)%Mod;
                if(c[j])
                {
                    sum=(1ll*sum+(1ll*x*pre)%Mod*(1ll*n-b[j])%Mod)%Mod;
                }
            }
        }
        
        
    
        for(i=0;i<=61;i++)
        {
            x=(1ll<<i)%Mod;
            for(j=0;j<=61;j++)
            {
                y=(1ll<<j)%Mod;
                y=1ll*y*x%Mod;
                s=1ll*b[i]*b[j]*b[j]%Mod;
                sum=(1ll*sum+1ll*s*y%Mod)%Mod;
            }
        }
//        cout<<sum<<endl;
        printf("%lld\n",(sum%Mod+Mod)%Mod);
    }
    
    return 0;
}
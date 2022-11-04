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
//#include <chrono>
//#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=20000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll gcd(ll a,ll b)
{
    if(a==0)
        return 1ll;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll pw[60];
ll b[maxn];

ll num;
ll prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
int pnum[maxn];
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn; i ++)
    {          //1~maxn
        if(sf[i])
        {
            prime[++num] = i;      //
            for(int j=i;j<maxn;j+=i)
            {
                pnum[j]++;
                sf[j]=0;
            }
            sf[i]=1;
        }
    }
}

int main()
{
//    sync;
    pw[0]=1ll;
    for(int i=1;i<=58;i++)
    {
        pw[i]=2ll*pw[i-1];
    }
    sushu();
    int t;
//    cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        ll c,d,x;
//        cin>>c>>d>>x;
        scanf("%lld%lld%lld",&c,&d,&x);
        int cnt=0;
        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                b[++cnt]=i;
                if(x/i!=i)
                    b[++cnt]=x/i;
            }
        }
        ll s,w,g;
        int j;
        ll ans=0ll;
        for(int i=1;i<=cnt;i++)
        {
            s=1ll*d*b[i]+x;
            if(s%c)
                continue;
            w=s/c;
            if(w%b[i])
                continue;
            w/=b[i];

            ans=1ll*ans+pw[pnum[w]];
        }
//        cout<<ans<<endl;
        printf("%lld\n",ans);
    }
    
    return 0;
}
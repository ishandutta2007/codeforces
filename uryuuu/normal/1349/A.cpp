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
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int vis[maxn];
int v[maxn];

ll num;
ll prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] > maxn) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

ll ksm(ll x,ll y)
{
    ll res=1ll;
    while(y)
    {
        if(y&1)
        {
            res=1ll*res*x;
        }
        x=1ll*x*x;
        y/=2ll;
    }
    return res;
}


int a[maxn];

int main()
{
//    sync;
    int n;
    sushu();
    int zd=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v[a[i]]++;
        zd=max(zd,a[i]);
    }
    ll d;
    ll ans=1ll;
    
    for(int k=1;k<=num;k++)
    {
        d=prime[k];
        int ct=0;
        if(d>zd)
            break;
        if(d*d>zd)
        {
            for(int i=1;i<=n;i++)
            {
                vis[i]=0;
                while(a[i]%d==0)
                {
                    vis[i]++;
                    a[i]/=d;
                }
                if(vis[i]==0)
                    ct++;
                zd=max(zd,a[i]);
                if(ct>=2)
                {
                    break;
                }
            }
            if(ct<=1)
            {
                ans=1ll*ans*d;
            }
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            while(a[i]%d==0)
            {
                vis[i]++;
                a[i]/=d;
            }
            if(vis[i]==0)
                ct++;
            zd=max(zd,a[i]);
            if(ct>=2)
            {
                break;
            }
        }
        if(ct>=2)
            continue;
        int id=0;
        int zx=99999;
        int c=99999;
        for(int i=1;i<=n;i++)
        {
            if(zx>vis[i])
            {
                zx=vis[i];
                id=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(c>vis[i]&&i!=id)
            {
                c=vis[i];
            }
        }
        
//        if(c)
//        {
//            cout<<d<<endl;
//            rep(i,1,n)
//            cout<<vis[i]<<' ';
//            cout<<endl;
//        }
        ans=1ll*ans*ksm(d,c);
    }
    printf("%lld\n",ans);
    
    return 0;
}
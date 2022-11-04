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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod = 998244353;
//#define int long long

ll p[maxn],inv[maxn];
int b[maxn];
map<int,ll>pls,mns;

ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

int main()
{
    sync;
    
    p[0]=inv[0]=1ll;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;

    
    int n,k;
    cin>>n>>k;
    int m=0;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        b[++m]=l;
        b[++m]=r;
        mns[r]++;
        pls[l]++;
    }
    
    sort(b+1,b+m+1);
    m=unique(b+1,b+m+1)-b-1;
    ll ans=0;
    ll sum=0;
    int x;
    for(int i=1;i<=m;i++)
    {
        x=b[i];
//        cout<<x<<' '<<sum<<' '<<pls[x]<<endl;
        if(pls[x]>0)
        {
            if(pls[x]+sum>=k)
            {
                ans=(1ll*ans+C(pls[x]+sum,k))%Mod;
                if(sum>=k)
                {
                    ans=(1ll*ans-C(sum,k))%Mod;
                }
            }
            sum+=pls[x];
        }
        sum-=mns[x];
    }
    cout<<(1ll*ans%Mod+Mod)%Mod;
    
    
    return 0;
}
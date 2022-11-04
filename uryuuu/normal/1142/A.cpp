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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll c[maxn];

long long gcd(long long a,long long b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}


int main()
{
    sync;
    int t;
    ll n,k;
    ll a,b;
    cin>>n>>k>>a>>b;
    ll s=1ll*n*k;
    ll d=1ll*b;
    int m=0;
    while(d<=s+a)
    {
//        cout<<d<<endl;
        if(d>=a)
        {
            c[m++]=d;
        }
        d+=1ll*k;
    }
    d=1ll*k-b;
    while(d<=s+a)
    {
//        cout<<d<<endl;
        if(d>=a)
        {
            c[m++]=d;
        }
        d+=1ll*k;
    }
    sort(c,c+m);
    ll zx=2e17,zd=-1;
    for(int i=0;i<m;i++)
    {
        zx=min(zx,1ll*s/gcd(s,c[i]-a));
        zd=max(zd,1ll*s/gcd(s,c[i]-a));
//        cout<<c[i]<<' '<<s<<' '<<gcd(s,c[i]-a)<<endl;
    }
    cout<<zx<<' '<<zd<<endl;
    return 0;
}
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
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn];

int main()
{
    sync;
   
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    ll s,L,R,l,r;
    for(ll i=c+1ll;i<=1000005;i++)
    {
        s=i;
        L=s-b;
        R=s-a;
        if(L>R)
            continue;
        if(R<b||L>c)
            continue;
        L=max(s-b,b);
        R=min(s-a,c);
        if(L>R)
            continue;
        ans=1ll*ans+1ll*(R-L+1ll)*(1ll*min(i,d+1)-c);
    }
    cout<<ans<<endl;
    
    return 0;
}
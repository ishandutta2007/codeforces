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
const int maxn=2000010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

int a[maxn],b[maxn];

int main()
{
//    sync;
    int n;
    ll m;
    scanf("%d%lld",&n,&m);
    int f=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
        {
            f=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]==1)
        {
            f=1;
        }
    }
    if(f)
    {
        printf("-1\n");
        return 0;
    }
    double ans=1.0*m;
    double d=1.0*ans/(1.0*(b[1]-1));
    ans=1.0*ans+d;
    for(int i=n;i>=2;i--)
    {
        d=1.0*ans/(1.0*(a[i]-1));
        ans=1.0*ans+d;
        d=1.0*ans/(1.0*(b[i]-1));
        ans=1.0*ans+d;
    }
    d=1.0*ans/(1.0*(a[1]-1));
    ans=1.0*ans+d-1.0*m;
    printf("%.10f\n",ans);
    return 0;
}
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
const int maxn=3000010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
//#define int long long

struct node
{
    ll x,y,val;
}a[maxn];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

ll dp[maxn];

int q[maxn];

ll qry(int i,int j)
{
    return dp[i]+(a[j].x-a[i].x)*a[j].y-a[j].val;
}

double xl(int i,int j)
{
    return (double)1.0*(dp[i]-dp[j])/(a[i].x-a[j].x);
}


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].val;
    }
    sort(a+1,a+n+1,cmp);
    ll ans=0;
    int L=0,R=0;
    for(int i=1;i<=n;i++)
    {
        while(L<R&&qry(q[L],i)<qry(q[L+1],i))
            L++;
        dp[i]=qry(q[L],i);
        ans=max(ans,dp[i]);
        while(L<R&&xl(q[R],q[R-1])<xl(i,q[R]))
            R--;
        q[++R]=i;
    }
    cout<<ans<<endl;
    return 0;
}
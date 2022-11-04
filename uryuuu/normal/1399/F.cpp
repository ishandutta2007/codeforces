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
const int maxn=6010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


int dp[maxn],x[maxn],n,m,t;

struct node
{
    int l,r,w;
}a[maxn];

bool cmp(node a,node b)
{
    if(a.r==b.r)
        return a.l>b.l;
    return a.r<b.r;
}

int main()
{
    sync;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].l>>a[i].r;
            a[i].w=1;
            x[++m]=a[i].l;
            x[++m]=a[i].r;
        }
        sort(a+1,a+n+1,cmp);
        sort(x+1,x+m+1);
        m=unique(x+1,x+m+1)-x-1;
        for(int i=1;i<=n;i++)
        {
            a[i].l=lower_bound(x+1,x+m+1,a[i].l)-x;
            a[i].r=lower_bound(x+1,x+m+1,a[i].r)-x;
        }
        a[++n].l=1;
        a[n].r=m;
        a[n].w=0;
        int L;
        for(int i=1;i<=n;i++)
        {
            dp[0]=0;
            L=1;
            for(int j=1;j<=m;j++)
            {
                dp[j]=dp[j-1];
                while(L<i&&a[L].r==j)
                {
                    if(a[L].l>=a[i].l&&a[L].r<=a[i].r)
                        dp[j]=max(dp[j],dp[a[L].l-1]+a[L].w);
                    L++;
                }
            }
            a[i].w+=dp[m];
        }
        cout<<a[n].w<<endl;
    }
    return 0;
}
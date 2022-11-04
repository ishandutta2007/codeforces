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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


double dp[205][205][205];

struct node
{
    int val;
    double p;
}a[205];

bool cmp(node a,node b)
{
    return a.val>b.val;
}

int main()
{
    int n,l,k;
    cin>>n>>l>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].p;
        a[i].p*=0.01;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i].val;
    sort(a+1,a+n+1,cmp);
    dp[0][0][min(n,k)]=1.0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int g=0;g<=n;g++)
            {
                dp[i+1][j][g]+=dp[i][j][g]*(1.0-a[i+1].p);
                if(g+a[i+1].val>=0)
                {
                    dp[i+1][j+1][min(n,g+a[i+1].val)]+=dp[i][j][g]*a[i+1].p;
                }
            }
        }
    }
    double ans=0.0;
    for(int i=l;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            ans+=dp[n][i][j];
        }
    }
    printf("%.7f\n",ans);
    
    return 0;
}
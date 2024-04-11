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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=10005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int dp[maxn][2005];
int a[maxn];
int n;

int check(int mid)
{
    for(int i=0;i<=mid;i++)
        dp[0][i]=1;
    int j;
    for(int i=1;i<=n;i++)
    {
        for(j=0;j<=mid;j++)
        {
            if(j+a[i]<=mid&&dp[i-1][j+a[i]])
                dp[i][j]=1;
            else if(j-a[i]>=0&&dp[i-1][j-a[i]])
                dp[i][j]=1;
            else
                dp[i][j]=0;
        }
    }
    for(int i=0;i<=mid;i++)
    {
        if(dp[n][i])
            return 1;
    }
    return 0;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int mn=1e9;
        int l=1,r=2000,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(check(mid))
            {
                r=mid;
                mn=min(mid,mn);
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
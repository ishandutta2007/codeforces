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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
const int maxn=5005;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;
int dp[maxn];
int lcp[maxn][maxn];
int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        for(int i=1;i<=n;i++)
        {
            a[i]=ch(s[i-1]);
        }
        
        int j;
        for(int i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
                lcp[i][j]=0;
        }
        for(int i=n;i>=1;i--)
        {
            for(j=n;j>i;j--)
            {
                if(a[i]==a[j])
                    lcp[j][i]=lcp[i][j]=lcp[i+1][j+1]+1;
            }
        }
        int ans=0,len;
        for(int i=1;i<=n;i++)
        {
            dp[i]=n-i+1;
            for(j=1;j<i;j++)
            {
                len=lcp[i][j];
                if(a[i+len]>a[j+len])
                {
                    dp[i]=max(dp[i],dp[j]+n-i-len+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
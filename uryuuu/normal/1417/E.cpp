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
const int maxn=9000010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int s[maxn][2];
ll dp[40][3];
ll sz[maxn][3];
int tot=1;

void insert(ll x)
{
    int rt=1;
    for(int i=30;i>=0;i--)
    {
        if(s[rt][0]==0)
            s[rt][0]=++tot;
        if(s[rt][1]==0)
            s[rt][1]=++tot;
        if(x&(1ll<<i))
        {
            dp[i][1]+=sz[rt][0];
            sz[rt][1]++;
            rt=s[rt][1];
        }
        else
        {
            dp[i][0]+=sz[rt][1];
            sz[rt][0]++;
            rt=s[rt][0];
        }
    }
}

int main()
{
    sync;
    int n;
    cin>>n;
    ll x;
    tot=1;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        insert(x);
    }
    ll sum=0;
    ll ans=0;
    for(int i=30;i>=0;i--)
    {
        if(dp[i][1]<dp[i][0])
        {
            sum+=dp[i][1];
            ans+=(1ll<<i);
        }
        else
        {
            sum+=dp[i][0];
        }
    }
    cout<<sum<<' '<<ans<<endl;
    
    return 0;
}
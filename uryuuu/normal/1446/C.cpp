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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;

int t[maxn*33][2];
int dp[maxn*33];
int tot=0;

void insert(ll x)
{
    int rt=1;
    ll d;
    for(int i=32;i>=0;i--)
    {
        d=((x>>i)&1);
        if(t[rt][d]==0)
            t[rt][d]=++tot;
        rt=t[rt][d];
        dp[rt]++;
    }
}

int ans=0;

int dfs(int rt)
{
    if(rt==0)
        return 0;
    if(t[rt][0]==0&&t[rt][1]==0)
        return dp[rt];
    int L=dfs(t[rt][0]);
    int R=dfs(t[rt][1]);
    return max(L+min(R,1),R+min(L,1));
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
    cout<<n-dfs(1);

    return 0;
}

/*

20
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
 
 */
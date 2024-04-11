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
const int maxn=1000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

map<int,int>mp[maxn];

int check(int r,int c,int l)
{
    if(r+c>maxn)
        return 1;
    return (l&&mp[l][r+c]==0);
}
int dp[maxn];
int pre[maxn],ans[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    int val,c,l,r;
    int cnt=0;
    int id=0;
    for(int i=1;i<=n;i++)
    {
        cin>>val>>c>>l>>r;
        if(check(r,c,l))
            continue;
        int pos=mp[l][r+c];
        dp[i]=dp[pos]+val;
        pre[i]=pos;
        if(r==0&&dp[i]>dp[id])
            id=i;
        if(dp[i]>dp[mp[l+c][r]])
            mp[l+c][r]=i;
    }
    while(id)
    {
        ans[++cnt]=id;
        id=pre[id];
    }
    cout<<cnt<<endl;
    for(int i=cnt;i>=1;i--)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
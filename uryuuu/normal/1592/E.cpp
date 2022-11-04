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
const int maxn=2000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],pre[maxn],pos[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0,sum,lst;
    for(int i=0;i<=20;i++)
    {
        mm(pos);
        for(int j=1;j<=n;j++)
        {
            pre[j]=pre[j-1];
            if(a[j]&(1<<i))
                pre[j]++;
        }
        sum=0;
        for(int j=1;j<=n;j++)
        {
            sum=sum^(a[j]>>i);
            lst=pos[sum];
            if(lst==0&&sum)
            {
                pos[sum]=j;
                continue;
            }
            if(j-lst==pre[j]-pre[lst])
            {
                ans=max(ans,j-lst);
            }
            else
                pos[sum]=j;
        }
    }
    cout<<ans<<endl;
    return 0;
}
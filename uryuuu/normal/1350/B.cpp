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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int vis[maxn];


int a[maxn];


int main()
{
//    sync;
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            vis[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=n;j++)
            {
                ll d=1ll*i*j;
                if(1ll*d>1ll*n)
                    break;
                if(a[d]>a[i])
                    vis[d]=max(vis[i]+1,vis[d]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=max(vis[i],ans);
        }

        printf("%d\n",ans);
    }
    
    return 0;
}
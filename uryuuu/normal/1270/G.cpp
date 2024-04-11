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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1000005;
const ll Mod=1e9+7;

int t,n,a[maxn];
vector<int>g[maxn];
int v[maxn];
vector<int>ans;
int main()
{
//    sync;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=i-a[i];
        }
        for(int i=1;i<=n;i++)
        {
            v[i]=0;
        }
        int now=1;
        do
        {
            v[now]=1;
            now=a[now];
        }while(v[now]==0);
        int u=now;
        ans.clear();
        do
        {
            ans.push_back(u);
            u=a[u];
        }while(u!=now);
//        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(auto x:ans)
            printf("%d ",x);
        puts("");
    }
    return 0;
}
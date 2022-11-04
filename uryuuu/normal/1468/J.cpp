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
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


int f[500005];
struct node
{
    ll x, y, w;
}p[500005];
int cmp(node a, node b)
{
    return a.w<b.w;
}
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
int un(int a, int b)
{
    int f1=find(a);
    int f2=find(b);
    if(f2!=f1)
    {
        f[f2]=f1;
        return 1;
    }
    return 0;
}



int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        for(int i=0; i<=n; i++)
        {
            f[i]=i;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%lld %lld %lld", &p[i].x, &p[i].y, &p[i].w);
        }
        sort(p+1, p+1+m, cmp);
        int cnt=0 ,f=0;
        ll res=0;
        ll sum=0;
        for(int i=1; i<=m; i++)
        {
            if(f==0)
            {
                if(un(p[i].x, p[i].y))
                {
                    cnt++;
                    if(cnt==n-1)
                    {
                        if(p[i].w>=k)
                        {
                            res+=p[i].w-k;
                            break;
                        }
                        else
                        {
                            res=k-p[i].w;
                            f=1;
                        }
                    }
                    else
                    {
                        if(p[i].w>=k)
                        {
                            sum+=p[i].w-k;
                        }
                    }
                }
            }
            else
            {
                res=min(res, abs(p[i].w-k));
            }
        }
        printf("%lld\n", 1ll*sum+res);
    }
}
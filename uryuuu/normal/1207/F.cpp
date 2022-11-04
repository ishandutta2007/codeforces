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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;


ll a[805][805],b[maxn];
ll x,y;
int fff;

int main()
{
//    sync;
    int q;
    scanf("%d",&q);
    ll d,x,y;
    ll m=ceil(sqrt(maxn));
    while(q--)
    {
        scanf("%lld%lld%lld",&d,&x,&y);
        if(d==1)
        {
            b[x]+=y;
            for(int j=1;j<=m;j++)
            {
                a[j][x%j]+=y;
            }
        }
        else
        {
            if(x<=m)
                printf("%lld\n",a[x][y]);
            else
            {
                ll s=0;
                for(int j=y;j<=500000;j+=x)
                    s+=b[j];
                printf("%lld\n",s);
            }
        }
    }
    return 0;
}
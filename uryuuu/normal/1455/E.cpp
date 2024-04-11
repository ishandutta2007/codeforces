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


ll a[5][5],p[10];
ll X[5],Y[5],x[5],y[5],nx[5],ny[5];

ll cal(ll d)
{
    for(int i=1;i<=4;i++)
    {
        nx[i]=x[i];
        ny[i]=y[i];
    }
    nx[2]-=d;
    nx[4]-=d;
    ny[3]-=d;
    ny[4]-=d;
    sort(nx+1,nx+5);
    sort(ny+1,ny+5);
    return 1ll*nx[4]+nx[3]-nx[2]-nx[1]+ny[4]+ny[3]-ny[2]-ny[1];
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=4;i++)
        {
            cin>>X[i]>>Y[i];
            p[i]=i;
        }
        ll ans=5e18;
        do
        {
            for(int i=1;i<=4;i++)
            {
                x[i]=X[p[i]];
                y[i]=Y[p[i]];
            }
            ans=min(ans,cal(x[2]-x[1]));
            ans=min(ans,cal(x[2]-x[3]));
            ans=min(ans,cal(x[4]-x[1]));
            ans=min(ans,cal(x[4]-x[3]));
            ans=min(ans,cal(y[3]-y[1]));
            ans=min(ans,cal(y[3]-y[2]));
            ans=min(ans,cal(y[4]-y[1]));
            ans=min(ans,cal(y[4]-y[2]));
        }while(next_permutation(p+1,p+5));
        cout<<ans<<endl;
    }
    
    return 0;
}
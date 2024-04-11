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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn];

int main()
{
    sync;
    ll lm=1e10;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    sort(a+1,a+n+1);
    int f=0;
    ll ans=3e17;
    for(int k=1;k<=200000;k++)
    {
        ll s=1ll;
        f=0;
        ll sum=1ll*abs(1-a[1]);
        for(int i=2;i<=n;i++)
        {
            s=1ll*s*k;
            if(s>lm)
            {
                f=1;
                break;
            }
            sum=1ll*sum+1ll*abs(s-a[i]);
        }
        if(f)
            break;
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
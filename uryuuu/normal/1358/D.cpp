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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=400010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn];
ll b[maxn];
ll s[maxn];
ll pre[maxn];

int main()
{
    sync;
    ll n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    int m=n;
    n*=2;
    reverse(a+1,a+n+1);
    s[0]=0;
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=1ll*(1ll+a[i])*a[i]/2ll;
        pre[i]=1ll*pre[i-1]+1ll*b[i];
        s[i]=1ll*s[i-1]+1ll*a[i];
    }
    ll mx=0;
    ll pos;
    ll sum;
    ll c;
    for(int i=1;i<=m;i++)
    {
        pos=lower_bound(s+i,s+n+1,1ll*x+s[i-1])-s;
        sum=1ll*pre[pos-1]-pre[i-1];
        c=1ll*s[i-1]+1ll*x-s[pos-1];
//        cout<<i<<' '<<sum<<' '<<c<<endl;
        sum=1ll*(1ll*a[pos]+a[pos]-c+1ll)*c/2ll+1ll*sum;
        mx=max(sum,mx);
    }
    cout<<mx<<endl;
    return 0;
}
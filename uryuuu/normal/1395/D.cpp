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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef pair<ll,ll> pll;
//const double pi=acos(-1);
const int maxn = 200010;
//const ll Mod=1000000007;
const ll Mod = 998244353;

ll n,d,m;
ll s[maxn],a[maxn],b[maxn],suma[maxn],sumb[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    sync;
    cin>>n>>d>>m;
    int c1=0,c2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]>m)
            a[++c1]=s[i];
        else
            b[++c2]=s[i];
    }
    sort(a+1,a+c1+1,cmp);
    sort(b+1,b+c2+1,cmp);
    suma[0]=sumb[0]=0;
    for(int i=1;i<=c1;i++)
    {
        suma[i]=1ll*suma[i-1]+a[i];
//        cout<<a[i]<<' ';
    }
//    cout<<endl;
    for(int i=1;i<=c2;i++)
    {
        sumb[i]=1ll*sumb[i-1]+b[i];
//        cout<<b[i]<<' ';
    }
//    cout<<endl;
    ll mx=0;
    ll sum;
    if(c1==0)
        mx=sumb[c2];
    for(int k=1;k<=c1;k++)
    {
        sum=0;
        if(1ll*(k-1ll)*(d+1)+1ll>n)
            break;
        if(1ll*(k-1ll)*d>=(c1-k))
        {
            sum=suma[k]+sumb[c2-(1ll*(k-1ll)*d-(c1-k))];
            mx=max(sum,mx);
        }
        else if(1ll*k*d>=(c1-k))
        {
            sum=suma[k]+sumb[c2];
            mx=max(sum,mx);
        }
    }
    cout<<mx<<endl;
    
    return 0;
}
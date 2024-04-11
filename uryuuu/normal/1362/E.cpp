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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn =1000010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
const ll mod=1004535809;


ll a[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

ll ksm1(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}

ll ksm2(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%mod;
        }
        x=x*x%mod;
        y/=2;
    }
    return res%mod;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll p;
        cin>>n>>p;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1,cmp);
        ll ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(ans1==0&&ans2==0)
            {
                ans1=((1ll*ans1+ksm1(p,a[i]))%Mod+Mod)%Mod;
                ans2=((1ll*ans2+ksm2(p,a[i]))%mod+mod)%mod;
            }
            else
            {
                ans1=((1ll*ans1-ksm1(p,a[i]))%Mod+Mod)%Mod;
                ans2=((1ll*ans2-ksm2(p,a[i]))%mod+mod)%mod;
            }
        }
        cout<<(ans1%Mod+Mod)%Mod<<endl;
        
    }
    return 0;
}
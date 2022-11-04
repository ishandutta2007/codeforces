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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=400005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll powmod(ll x,ll y)
{
    ll ans=1ll;
    while(y)
    {
        if(y&1)
            ans=ans*x%Mod;
        x=x*x%Mod;
        y>>=1;
    }
    return ans%Mod;
}

int n,k,a[maxn];
vector<int>v;
int main()
{
    sync;
    ll x;
    while(cin>>n)
    {
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            ans=(ans+1)%Mod*100%Mod*powmod(x,Mod-2)%Mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
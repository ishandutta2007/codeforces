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
const int maxn=100005;
const ll Mod=1e9+7;

ll eular(ll x)
{
    ll ans=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ans=ans/i*(i-1);
            while(x%i==0)
            {
                x/=i;
            }
        }
    }
    if(x>1)
        ans=ans/x*(x-1);
    return ans;
}

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int t;
int main()
{
    sync;
    cin>>t;
    ll a,m;
    while(t--)
    {
        cin>>a>>m;
        ll x=gcd(a,m);
        x=m/x;
        cout<<1ll*eular(x)<<endl;
    }
    return 0;
}
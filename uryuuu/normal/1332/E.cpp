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
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=2000010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

ll ksm(ll x,ll y)
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

int main()
{
    ll n,m,L,R;
    cin>>n>>m>>L>>R;
    ll d=1ll*(R-L+1);
    if(d==1)
    {
        cout<<1<<endl;
        return 0;
    }
    ll ou=1ll*(R/2*2-(L+1)/2*2)/2+1;
    ll qi=d-ou;
    if(1ll*n*m%2)
        cout<<ksm(1ll*(R-L)+1,1ll*n*m)<<endl;
    else
    {
        cout<<(ksm(1ll*(qi+ou),n*m)+ksm(qi-ou,n*m)+Mod+Mod)%Mod*ksm(2ll,Mod-2)%Mod;
    }
    return 0;
}
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
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;

long long gcd(long long a,long long b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}

ll s[maxn];

ll solve(ll x,ll c,ll d)
{
    x=1ll*x+1ll;
    ll h=x/c*d;
    ll g=x%c;
    h+=min(g,d);
    return h;
}

int main()
{
    sync;
    int t;
    ll a,b,q;
    ll x,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>q;
        ll c=a*b/gcd(a,b);
        ll d=max(a,b);
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            s[i]=1ll*(y-x+1)-(1ll*solve(y,c,d)-1ll*solve(x-1,c,d));
            cout<<s[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
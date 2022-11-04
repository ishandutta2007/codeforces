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
//#include<map>
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
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn = 300010;
//const ll Mod=1000000007;
const ll Mod = 998244353;


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


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll m,d,w;
        cin>>m>>d>>w;
        ll md=min(m,d);
        ll x=(d-1)%w;
        if(x==0)
        {
            cout<<md*(md-1)/2<<endl;
            continue;
        }
        ll y=x*w/gcd(w,x);
        y=y/x;
    
        ll mo=(md-1)/y;
        
        ll ans=1ll*((md-1ll)%y+1ll)*mo+(mo-1)*mo/2*y;
        cout<<ans<<endl;
        
    }
    return 0;
}
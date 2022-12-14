#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};
int pre[maxn][150];

ll phi(ll n)
{ 
     ll res=n,a=n;  
     for(ll i=2;i*i<=a;i++)
	 {  
         if(a%i==0)
		 {  
             res=res/i*(i-1);//   
             while(a%i==0) a/=i;  
         }  
     }  
     if(a>1) res=res/a*(a-1);  
     return res;
} 

ll solve()
{
    ll a,m;
    cin>>a>>m;
    ll gc=__gcd(a,m);
    a/=gc,m/=gc;
    return phi(m);
}

int main()
{
    // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        printf("%lld\n",solve());
    }
    return 0;
}
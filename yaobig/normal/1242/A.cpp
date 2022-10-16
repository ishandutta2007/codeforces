#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int main()
{
    ll n; scanf("%I64d",&n);
    vector<ll> p;
    for(int i=2;1ll*i*i<=n;i++)
    {
        if(n%i==0)
        {
            p.pb(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) p.pb(n);
    if(p.size()==1) printf("%lld\n",p[0]);
    else puts("1");
    return 0;
}
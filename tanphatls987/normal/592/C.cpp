#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("cf.inp","r",stdin)
#define OUTPUT freopen("cf.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int main(){
    ll n,t1,t2;
    cin>>n>>t1>>t2;
    if (t1>t2) swap(t1,t2);
    ll lcm=(t1/__gcd(t1,t2));
    if (lcm<=n/t2) lcm*=t2;
    else lcm=n+1;
    ///
    ll ans=(n/lcm)*t1+min(t1,n%lcm+1)-1;
    ll tmp=__gcd(ans,n);
    cout<<ans/tmp<<'/'<<n/tmp;
}
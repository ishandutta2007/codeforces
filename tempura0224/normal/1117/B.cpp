#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    ll ans=0;
    ll cnt=m/(k+1);
    ans+=cnt*(k*a[0]+a[1]);
    ans+=(m%(k+1))*a[0];
    cout<<ans<<endl;
    return 0;
}
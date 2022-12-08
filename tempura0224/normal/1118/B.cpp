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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)scanf("%lld",&a[i]);
    vector<ll> sum(n+1),rsum(n+1);
    rep(i,n){
        sum[i+1]=a[i]-sum[i];
        rsum[n-i-1]=a[n-i-1]-rsum[n-i];
    }
    int ans=0;
    rep(i,n){
        if(sum[i]==rsum[i+1])++ans;
    }
    cout<<ans<<endl;
    return 0;
}
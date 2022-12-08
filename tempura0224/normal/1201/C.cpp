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
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    ll ok = 0, ng = 3e9;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        rep(i,(n+1)/2){
            cnt+=max(0ll,mid-a[i]);
        }
        if(cnt<=k)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    return 0;
}
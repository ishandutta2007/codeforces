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
    ll a,b;
    cin>>a>>b;
    if(a<b){
        cout<<-1<<endl;
        return 0;
    }
    ll s=a+b;
    ll ng = 3e9, ok=0;
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        if(s<2*mid*b){
            ng=mid;
        }
        else ok=mid;
    }
    double ans=1.0*s/2.0/ok;
    ng = 3e9, ok=0;
    s=a-b;
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        if(s<2*mid*b){
            ng=mid;
        }
        else ok=mid;
    }
    ans=min(ans,1.0*s/2.0/ok);
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
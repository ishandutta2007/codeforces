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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> x, y;
        rep(i,2*n){
            ll s, t;
            cin>>s>>t;
            if(s){
                x.push_back(abs(s));
            } else {
                y.push_back(abs(t));
            }
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        long double ans = 0 ;
        rep(i,n)ans+=sqrtl(x[i]*x[i]+y[i]*y[i]);
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    return 0;
}
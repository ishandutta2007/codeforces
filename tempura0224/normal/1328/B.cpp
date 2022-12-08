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
        int n;cin>>n;
        ll k;cin>>k;
        rep(i,n){
            ll cur = (ll)(n-i-1)*(n-i-2)/2;
            ll t = k-cur;
            if(1<=t && t < n-i){
                rep(k,i)cout<<'a';
                cout<<'b';
                rep(k,n-i-t-1)cout<<'a';
                cout<<'b';
                rep(k,t-1)cout<<'a';
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}
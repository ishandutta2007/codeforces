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
    set<ll> st;
    for(ll i=1;i<=10000;i++){
        st.insert(i*i*i);
    }
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        bool ok=false;
        for(auto e: st){
            if(st.count(x-e))ok=true;
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}
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
        ll x;cin>>x;
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        sort(a.rbegin(),a.rend());
        ll ans = 0;
        ll sum = 0;
        while(ans<n && (ans+1)*x<=sum+a[ans])sum+=a[ans++];
        cout<<ans<<endl;
    }
    return 0;
}
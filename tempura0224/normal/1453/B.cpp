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
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        vector<ll> d(n-1);
        rep(i,n-1)d[i]=a[i+1]-a[i];
        ll ans = longinf;
        ll sum=0;
        rep(i,n-1)sum+=abs(d[i]);
        rep(i,n-2){
            ans = min(ans, sum + abs(a[i+2]-a[i])-abs(d[i])-abs(d[i+1]));
        }
        ans=min(ans,sum-abs(d[0]));
        ans=min(ans,sum-abs(d[n-2]));
        cout<<ans<<endl;
    }
    return 0;
}
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
        vector<int> c(n);
        rep(i,n)cin>>c[i];
        vector<ll> a(n),b(n);
        rep(i,n)cin>>a[i];
        rep(i,n)cin>>b[i];
        rep(i,n)if(a[i]>b[i])swap(a[i],b[i]);
        ll cur = 0;
        ll ans = 0;
        for(int i=1;i<n;i++){
            if(a[i]==b[i]){
                cur = c[i]+1;
                ans = max(ans, cur);
            } else {
                cur = max(cur + c[i]+1-(b[i]-a[i]), (ll)c[i]+1+b[i]-a[i]);
                ans = max(ans, cur);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
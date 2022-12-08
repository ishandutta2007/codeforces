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
        map<int,int> mp;
        rep(i,n){
            int x;cin>>x;
            mp[x]++;
        }
        int cnt = 0;
        vector<int> a(n+1);
        int sz = 0;
        for(auto e: mp){
            a[e.second]++;
            sz++;
        }
        ll ans = inf;
        rep(i,n+1){
            ans = min(n - (ll)(sz-cnt)*i, ans);
            cnt+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
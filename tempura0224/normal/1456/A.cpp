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
        int n,k,p;
        cin>>n>>p>>k;
        string s;
        cin>>s;
        ll x,y;
        cin>>x>>y;
        --p;
        s = s.substr(p);

        n = s.size();
        ll ans = longinf;
        vector<int> cnt(n); 
        rep(i,n){
            cnt[i] = s[n-i-1]=='1' ? 0 : 1;
            if(i>=k)cnt[i]+=cnt[i-k];
            ans = min(ans, cnt[i]*x+(n-i-1)*y);
        }
        cout<<ans<<endl;
    }
    return 0;
}
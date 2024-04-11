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
constexpr ll mod=998244353 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    rep(i,n)cin>>p[i];
    ll ans = 1, sum = 0;
    ll pre = -1;
    rep(i,n){
        if(p[i]>n-k){
            sum += p[i];
            if(pre!=-1)ans = ans * (i-pre)%mod;
            pre=i;
        }
    }
    cout<<sum<<" "<<ans<<endl;
    return 0;
}
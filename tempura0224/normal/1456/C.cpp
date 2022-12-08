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
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    vector<ll> b;
    ll s = 0;
    ll ans = 0;
    rep(i,n){
        if(s<0){
            b.push_back(-s);
            REP(j,i,n)b.push_back(-a[j]);
            break;
        }
        ans += s;
        s += a[i];
    }
    ++k;
    vector<ll> sum(k);
    n = b.size();
    sort(b.begin(),b.end());
    rep(i,n){
        ans -= sum[i%k];
        sum[i%k]+=b[i];
    }
    cout << ans << endl;
    return 0;
}
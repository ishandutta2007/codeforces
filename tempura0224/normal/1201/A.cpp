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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m;
    cin>>n>>m;
    string s[n];
    rep(i,n)cin>>s[i];
    ll a[m];
    rep(i,m)cin>>a[i];
    ll ans = 0;
    rep(i,m){
        vector<int> cnt(5);
        rep(j,n)cnt[s[j][i]-'A']++;
        ans += *max_element(cnt.begin(), cnt.end())*a[i];
    }
    cout<<ans<<endl;
    return 0;
}
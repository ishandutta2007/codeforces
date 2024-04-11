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
    ll n,l;
    cin>>n>>l;
    l*=8;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int k = 0;
    while(n*k<=l)++k;
    --k;
    k = 1ll<<min(k,30);
    ll ans = inf;
    int cnt = 0;
    int pre = -1;
    int r = 0;
    rep(i,n){
        while(r<n&&cnt<=k){
            if(a[r]!=pre){
                ++cnt;
            }
            pre=a[r];
            ++r;
        }
        if(cnt>k){
            --cnt;
            --r;
            pre=a[r-1];
        }
        ans = min(ans,i+n-r);
        if(i<n-1&&a[i]!=a[i+1])--cnt;
    }
    cout<<ans<<endl;
    return 0;
}
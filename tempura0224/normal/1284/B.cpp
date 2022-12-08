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
    ll n;
    cin>>n;
    vector<int> a,b;
    ll cnt= 0;
    rep(i,n){
        int k;
        cin>>k;
        int mi = inf,ma=-1;
        bool ok=false;
        rep(j,k){
            int x;cin>>x;
            if(x>mi)ok=true;
            mi=min(x,mi);
            ma=max(ma,x);
        }
        if(ok)++cnt;
        else {
            a.push_back(mi);
            b.push_back(ma);
        }
    }
    sort(a.begin(),a.end());
    ll ans = n*n-(n-cnt)*(n-cnt);
    for(auto e:b){
        int itr = lower_bound(a.begin(),a.end(),e)-a.begin();
        ans += itr;
    }
    cout<<ans<<endl;
    return 0;
}
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a(n+1);
    rep(i,n)cin>>a[i+1];
    ll sum=0;
    rep(i,n){
        sum+=a[i+1];
    }
    vector<ll> b(n+1);
    ll ans = sum;
    int q;
    cin>>q;
    map<pair<int,int>,int>mp;
    rep(i,q){
        int x,y,z;
        cin>>x>>y>>z;
        int p = mp[{x,y}];
        if(p>0){
            if(b[p]<=a[p])++ans;
            --b[p];
        }
        if(z>0){
            ++b[z];
            if(b[z]<=a[z])--ans;
        }
        mp[{x,y}]=z;
        cout<<ans<<"\n";
    }
    return 0;
}
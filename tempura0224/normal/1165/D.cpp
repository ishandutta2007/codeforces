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

ll solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> used(1<<20);
    rep(i,n){
        cin>>a[i];
        used[a[i]]=1;
    }
    sort(a.begin(),a.end());
    ll ans=a[0]*a[n-1];
    rep(i,(n+1)/2){
        ll ret=a[i]*a[n-1-i];
        if(ans!=ret)return -1;
    }
    REP(i,2,1<<20){
        if(ans%i==0){
            if(i!=ans&&!used[i])return -1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
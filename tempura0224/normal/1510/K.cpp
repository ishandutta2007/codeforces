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
    int n;
    cin>>n;
    vector<int> a(2*n);
    rep(i,2*n)cin>>a[i];
    vector<int> b=a;
    int ans = inf;
    rep(t, 4*n){
        bool ok=1;
        rep(i,2*n){
            if(a[i]!=i+1)ok=0;
        }
        if(ok){
            ans=min(t, ans);
        }
        if(t%2==0){
            rep(i,n)swap(a[i],a[i+n]);
        } else {
            rep(i,n)swap(a[2*i],a[2*i+1]);
        }
    }
    rep(t, 4*n){
        bool ok=1;
        rep(i,2*n){
            if(b[i]!=i+1)ok=0;
        }
        if(ok){
            ans=min(t, ans);
        }
        if(t%2==1){
            rep(i,n)swap(b[i],b[i+n]);
        } else {
            rep(i,n)swap(b[2*i],b[2*i+1]);
        }
    }
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
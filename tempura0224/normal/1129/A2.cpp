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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> a[n];
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        a[x].push_back((y-x+n)%n);
    }
    rep(i,n)if(a[i].size())sort(a[i].rbegin(),a[i].rend());
    rep(i,n){
        ll ans=0;
        rep(j,n){
            ll cnt=a[j].size();
            if(cnt)ans=max(ans,n*(cnt-1)+a[j].back()+(j-i+n)%n);
        }
        printf("%lld ",ans);
    }
    return 0;
}
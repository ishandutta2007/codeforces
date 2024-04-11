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
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a(n);
        rep(i,n)cin>>a[i];
        k = min(k,m-1);
        int ans = 0;
        rep(i,k+1){
            int st = i,en=n-1-(k-i);
            int ret = inf;
            rep(j,m-k){
                ret = min(ret,max(a[st+j],a[en-(m-k-1-j)]));
            }
            ans = max(ans,ret);
        } 
        cout<<ans<<endl;
    }
    return 0;
}
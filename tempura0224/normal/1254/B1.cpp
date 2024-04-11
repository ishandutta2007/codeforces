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
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int sum = 0;
    rep(i,n)sum+=a[i];
    vector<int> b;
    rep(i,n)if(a[i]==1)b.push_back(i);
    ll ans = longinf;
    REP(j,2,sum+1){
        if(sum%j!=0)continue;
        ll res = 0;
        int cnt = sum/j;
        rep(i,cnt){
            int t = b[j*i+(j-1)/2];
            rep(k,j){
                res += abs(b[j*i+k]-t);
            }
        }
        ans = min(ans,res);
    }
    if(ans==longinf)cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}
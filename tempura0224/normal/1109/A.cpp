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
    vector<int> cnt1(1<<20),cnt0(1<<20);
    cnt0[0]++;
    int s = 0;
    ll ans = 0;
    rep(i,n){
        int x;cin>>x;
        s^=x;
        if(i%2==0){
            ans += cnt1[s]++;
        }
        else {
            ans += cnt0[s]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
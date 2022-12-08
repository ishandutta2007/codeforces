#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

ll mpow(ll x,ll k){
    ll ret = 1;
    while(k>0){
        if(k&1LL)
            ret = ret * x % mod;
        x = x * x % mod;
        k /= 2LL;
    }
    return ret;
}
int main(){
    ll x, y;
    cin >> x >> y;
    if(x==0){
        cout << 0 << endl;
        return 0;
    }
    x = (2 * x - 1) % mod;
    ll ans = mpow(2, y) * x + 1;
    ans%=mod;
    cout << ans<< endl;
    return 0;
}
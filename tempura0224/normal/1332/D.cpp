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
    int k;
    cin>>k;
    int ma = 1;
    while(ma<=2*k)ma*=2;
    --ma;
    int rk = ma-k;
    cout<<2<<" "<<3<<endl;
    cout<<ma<<" "<<k<<" "<<0<<endl;
    cout<<rk<<" "<<ma<<" "<<k<<endl;
    return 0;
}
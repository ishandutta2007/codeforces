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
    ll n;
    cin>>n;
    if(n%2==0){
        cout<<n/2<<endl;
        return 0;
    }
    ll ret = n;
    for(int i=2;i<=1000000;i++){
        if(n%i==0){
            ret=min((ll)i, ret);
        }
    }
    cout << (n-ret)/2+1<<endl;
    return 0;
}
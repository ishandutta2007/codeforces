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
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int ans = 0;
        while(n%5==0){
            n/=5;
            n*=4;
            ++ans;
        }
        while(n%3==0){
            n/=3;
            n*=2;
            ++ans;
        }
        while(n%2==0){
            n/=2;
            ++ans;
        }
        if(n==1)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
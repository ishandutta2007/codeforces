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
        int n,m;
        cin>>n;
        vector<int> b(n);
        rep(i,n)cin>>b[i];
        cin>>m;
        vector<int> r(m);
        rep(i,m)cin>>r[i];
        int ma1 = 0, ma2 = 0;
        int s = 0;
        rep(i,n){
            s += b[i];
            ma1=max(ma1,s);
        }
        s=0;
        rep(i,m){
            s+=r[i];
            ma2=max(ma2,s);
        }
        cout<<ma1+ma2<<endl;
    }
    return 0;
}
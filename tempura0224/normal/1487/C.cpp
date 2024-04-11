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
        int n;
        cin>>n;
        vector<vector<int>> res(n, vector<int>(n));
        rep(i,n){
            rep(j,(n-1)/2){
                res[i][(i+j+1)%n]=1;
            }
            rep(j,(n-1)/2){
                res[i][((i-j-1)%n+n)%n]=-1;
            }
        }
        rep(i,n)rep(j,n)assert(res[i][j]+res[j][i]==0);
        rep(i,n){
            REP(j,i+1,n)cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
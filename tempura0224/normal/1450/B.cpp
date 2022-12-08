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
        int n,k;
        cin>>n>>k;
        vector<int> x(n),y(n);
        rep(i,n)cin>>x[i]>>y[i];
        bool can=false;
        rep(i,n){
            bool ok=true;
            rep(j,n){
                int d = abs(x[i]-x[j])+abs(y[i]-y[j]);
                if(d>k)ok=false;
            }
            if(ok)can=true;
        }
        if(can)cout<<1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
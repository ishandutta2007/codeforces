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
    int n,m;
    cin>>m>>n;
    vector<int> ans(n*m);
    rep(i,n*m/2){
        ans[2*i]=i;
        ans[2*i+1]=n*m-1-i;
    }
    if(n*m%2)ans[n*m-1]=n*m/2;
    rep(i,n*m){
        int x = ans[i]%m;
        int y = ans[i]/m;
        printf("%d %d\n",x+1,y+1);
    }
    return 0;
}
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
const ll mod=998244353 ;

vector<int> v[202020];
ll dfs(int x,int p){
    ll ret=1;
    int cnt=1;
    for(auto to : v[x]){
        if(to==p)continue;
        ret = ret * dfs(to,x) %mod;
        ret = ret * cnt %mod;
        ++cnt;
    }
    if (x) ret = ret * cnt %mod;
    return ret;
}
int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<dfs(0,-1) * n % mod <<endl;
    return 0;
}
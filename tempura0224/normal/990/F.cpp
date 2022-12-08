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

vector<int> a(202020), used(202020), ans(202020);
vector<pair<int,int>> v[202020];

int dfs(int x, int p){
    int d = 0;
    used[x]=1;
    for(auto to: v[x]){
        if(to.first == p){
            d = to.second;
            continue;
        }
        if(used[to.first])continue;
        a[x]+=dfs(to.first, x);
    }
    if(d>0)ans[d]=-a[x];
    else ans[-d]=a[x];
    return a[x];
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,n)cin>>a[i];
    int m;cin>>m;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].emplace_back(y, i+1);
        v[y].emplace_back(x, -i-1);
    }
    int ret = dfs(0,-1);
    if(ret!=0){
        cout<<"Impossible"<<endl;
        return 0;
    } else {
        cout<<"Possible"<<endl;
        rep(i,m){
            cout<<ans[i+1]<<endl;
        }
    }
    return 0;
}
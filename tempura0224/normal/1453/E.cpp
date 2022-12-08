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


vector<int> v[202020];
int depth[202020];
void dfs1(int x, int p){
    for(auto to: v[x]){
        if(to==p)continue;
        depth[to]=depth[x]+1;
        dfs1(to,x);
    }
}
int ans;
int dfs2(int x, int p){
    if(x && v[x].size()==1)return depth[x];
    vector<int> ds;
    for(auto to: v[x]){
        if(to==p)continue;
        ds.push_back(dfs2(to,x));
    }
    sort(ds.begin(),ds.end());
    if(x){
        if(ds.size()>=2)ans = max(ds.back()-depth[x]+1, ans);
        return ds[0];
    } else {
        int m=ds.size();
        if(m>=2){
            ans = max(ds[m-2]-depth[x]+1, ans);
        }
        ans = max(ds[m-1], ans);
        return 0;
    }
}


void solve(){
    int n;
    cin>>n;
    rep(i,n)v[i].clear();
    ans = 0;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    cout<<ans<<endl;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
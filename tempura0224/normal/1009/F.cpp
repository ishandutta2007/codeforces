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
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> ans(n);
    vector<int> ma(n);
    auto dfs = [&](auto&& self, int x, int p) -> vector<int> {
        vector<int> ret = {};
        for(auto to: v[x]){
            if(to==p)continue;
            auto res = self(self, to, x);
            if(res.size()>ret.size()){
                if(ma[to]>ma[x]){
                    ans[x]=ans[to] + 1;
                    ma[x]=ma[to];
                }
                swap(res,ret);
            }
            int n = res.size(), m=ret.size();
            rep(i,n){
                ret[m-n+i]+=res[i];
                if(ret[m-n+i]>=ma[x]){
                    ma[x]=ret[m-n+i];
                    ans[x]=n-i;
                }
            }
        }
        ret.push_back(1);
        if(ma[x]<=1)ans[x]=0;
        return ret;
    };
    dfs(dfs,0,-1);
    rep(i,n)cout<<ans[i]<<"\n";
    return 0;
}
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

vector<pair<int,ll>> v[505050];
int k;
pair<ll,ll> dfs(int x,int p){
    vector<pair<ll,ll>> res;
    for(auto to:v[x]){
        if(to.first==p)continue;
        auto ret=dfs(to.first,x);
        res.emplace_back(ret.first+to.second,ret.second);
    }
    sort(res.begin(),res.end(),[](auto w,auto z){
        return w.first-w.second>z.first-z.second;
    });
    ll ret1=0, ret2=0;
    rep(i,res.size()){
        if(i<k)ret2+=max(res[i].first,res[i].second);
        else ret2+=res[i].second;
        if(i<k-1)ret1+=max(res[i].first,res[i].second);
        else ret1+=res[i].second;
    }
    return {ret1,ret2};
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        scanf("%d%d",&n,&k);
        rep(i,n)v[i].clear();
        rep(i,n-1){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            --x;--y;
            v[x].emplace_back(y,z);
            v[y].emplace_back(x,z);
        }
        auto ret=dfs(0,-1);
        printf("%lld\n",max(ret.first,ret.second));
    }
    
    return 0;
}
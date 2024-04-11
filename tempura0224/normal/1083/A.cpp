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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll ans,a[303030];
vector<pll> v[303030];

ll dfs(int x,int p){
    ll ma=0,se=0;
    for(auto to:v[x]){
        if(to.first==p)continue;
        ll res=dfs(to.first,x)-to.second;
        if(res>=ma){
            se=ma;
            ma=res;
        }
        else if(res>se){
            se=res;
        }
    }
    ans=max(ans,ma+se+a[x]);
    return ma+a[x];
}

int main(){
    int n;cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n-1){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    dfs(0,-1);
    cout<<ans<<endl;
    return 0;
}
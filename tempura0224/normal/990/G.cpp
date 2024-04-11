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

vector<int> a(202020), v[202020];
vector<ll>ans(202020);

int gcd(int x, int y){
    return y ? gcd(y, x%y) : x;
}

map<int,int> dfs(int x, int p){
    map<int,int> mp;
    mp[a[x]]++;
    ans[a[x]]++;
    for(auto to: v[x]){
        if(to==p)continue;
        auto res = dfs(to, x);
        for(auto e: res){
            int g = gcd(e.first, a[x]);
            for(auto f: mp){
                ans[gcd(g,f.first)]+=(ll)f.second*e.second;
            }
        }
        for(auto e: res){
            mp[gcd(e.first,a[x])]+=e.second;
        }
    }
    return mp;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0,-1);
    for(int i=1;i<=200000;i++){
        if(ans[i]){
            cout<<i<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}
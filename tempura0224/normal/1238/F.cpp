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

vector<pair<int,int>> v[303030];
int sz[303030];
void dfs(int x,int p){
    for(auto to:v[x]){
        if(to.first==p)continue;
        sz[to.first]=sz[x]+to.second;
        dfs(to.first,x);
    }
}



int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        rep(i,n)v[i].clear();
        rep(i,n-1){
            int x,y;
            cin>>x>>y;
            --x;--y;
            v[x].push_back({y,0});
            v[y].push_back({x,0});
        }
        rep(i,n){
            for(auto &to:v[i])to.second = v[to.first].size()+v[i].size()-2;
        }
        sz[0]=0;
        dfs(0,-1);
        int idx = max_element(sz,sz+n)-sz;
        sz[idx]=0;
        dfs(idx,-1);
        cout<<(*max_element(sz,sz+n))/2+2<<endl;
    }
    return 0;
}
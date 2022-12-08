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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> ord(n);
    rep(i,n)ord[i]=i;
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return a[x]<a[y];
    });
    vector<int> ans;
    vector<int> cur(n,1);
    for(auto i:ord){
        if(cur[i]!=a[i]){
            cout<<-1<<endl;
            return 0;
        }
        for(auto to:v[i]){
            if(cur[to]==a[i])++cur[to];
        }
        ans.push_back(i+1);
    }
    for(auto e:ans)cout<<e<<" ";
    return 0;
}
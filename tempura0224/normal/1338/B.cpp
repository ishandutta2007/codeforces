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
    vector<int> cnt(n);
    int ma=0;
    rep(i,n){
        if(v[i].size()==1){
            if(++cnt[v[i][0]]>1)++ma;
        }
    }
    vector<int> col(n);
    col[0]=1;
    queue<int> q;
    q.push(0);
    while(q.size()){
        int x=q.front();q.pop();
        for(auto to:v[x]){
            if(col[to]==0){
                col[to]=-col[x];
                q.push(to);
            }
        }
    }
    bool one=false, zero=false;
    rep(i,n){
        if(v[i].size()==1){
            if(col[i]==1)one=true;
            else zero=true;
        }
    }
    if(one && zero)cout<<3<<" "<<n-1-ma<<endl;
    else cout<<1<<" "<<n-1-ma<<endl;
    return 0;
}
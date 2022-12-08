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

ll d[1212][1212];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    rep(i,2*n)rep(j,2*n)d[i][j]=longinf;
    rep(i,2*n)d[i][i]=0;
    vector<int> u(m),v(m),w(m);
    rep(i,m){
        cin>>u[i]>>v[i]>>w[i];
        --u[i];--v[i];
        d[u[i]][v[i]]=w[i];
        d[u[i]+n][v[i]+n]=w[i];
        d[v[i]][u[i]]=w[i];
        d[v[i]+n][u[i]+n]=w[i];
    }
    int q;
    cin>>q;
    rep(i,q){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        d[x][y+n]=-z;
        d[y][x+n]=-z;
    }
    rep(i,2*n)rep(j,2*n)rep(k,2*n){
        d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
    }
    int ans = 0;
    rep(i,m){
        if(w[i]+d[u[i]][v[i]+n]<=0)++ans;
    }
    cout<<ans<<endl;
    return 0;
}
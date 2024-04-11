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
constexpr ll mod = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    vector<vector<int>> d(n, vector<int>(n,inf));
    rep(i,n)d[i][i]=0;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
        d[x][y]=d[y][x]=1;
    }
    rep(i,n)rep(j,n)rep(k,n){
        d[j][k]=min(d[i][j]+d[i][k],d[j][k]);
    }
    rep(l, n)rep(r, n){
        vector<int> path(n, false);
        path[l]=path[r]=1;
        int cur = l;
        while(cur!=r){
            path[cur]=1;
            for(auto to: v[cur]){
                if(d[l][to]+d[to][r]==d[l][r]&&d[l][to]>d[l][cur]){
                    cur = to;
                    break;
                }
            }
        }
        ll ans = 1;
        rep(i,n){
            if(path[i])continue;
            int cnt = 0;
            for(auto to: v[i]){
                if(d[l][to]<d[l][i]&&d[r][to]<d[r][i])++cnt;
            }
            ans = ans * cnt % mod;
        }
        cout<<ans<<" \n"[r+1==n];
    }
    return 0;
}
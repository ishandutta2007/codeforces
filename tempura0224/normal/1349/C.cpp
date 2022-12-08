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


ll dist[1000][1000][2];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,t;
    cin>>h>>w>>t;
    string s[h];
    rep(i,h)cin>>s[i];
    queue<pair<pair<int,int>,int>> q;
    rep(i,h)rep(j,w){
        if(s[i][j]=='1'){
            dist[i][j][1]=0;
            q.push({{i,j},1});
            dist[i][j][0]=longinf;
        }
        else {
            dist[i][j][0]=0;
            q.push({{i,j},0});
            dist[i][j][1]=longinf;
        }
    }
    int d[] = {1,0,-1,0,1};
    while(q.size()){
        auto tri = q.front();q.pop();
        int x=tri.first.first, y=tri.first.second;
        rep(i,4){
            int nx=x+d[i], ny=y+d[i+1];
            if(nx<0||nx>=h||ny<0||ny>=w)continue;
            if(dist[nx][ny][!tri.second]==longinf){
                dist[nx][ny][!tri.second]=dist[x][y][tri.second]+1;
                q.push({{nx,ny},!tri.second});
            }
        }
    }
    while(t--){
        int x,y;
        ll p;
        cin>>x>>y>>p;
        --x;--y;
        if(dist[x][y][0]<=p && dist[x][y][1]<=p){
            if(dist[x][y][0]>dist[x][y][1]){
                cout<<(dist[x][y][0]%2 != p%2)<<'\n';
            }
            else {
                cout<<(dist[x][y][1]%2 == p%2)<<'\n';
            }
        }
        else if(dist[x][y][0]<=p){
            cout<<0<<'\n';
        }
        else cout<<1<<'\n';
    }
    return 0;
}
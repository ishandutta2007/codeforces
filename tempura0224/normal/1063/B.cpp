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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
    int n,m;
    cin>>n>>m;
    int r,c;
    cin>>r>>c;
    --r;--c;
    int ld,rd;
    cin>>ld>>rd;
    string s[n];
    rep(i,n)cin>>s[i];
    int dist[n][m];
    rep(i,n)rep(j,m)dist[i][j]=inf;
    deque<pint> q;
    q.emplace_back(r,c);
    dist[r][c]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop_front();
        if(x>0&&s[x-1][y]!='*'&&dist[x-1][y]>dist[x][y]){
            dist[x-1][y]=dist[x][y];
            q.emplace_front(x-1,y);
        }
        if(x<n-1&&s[x+1][y]!='*'&&dist[x+1][y]>dist[x][y]){
            dist[x+1][y]=dist[x][y];
            q.emplace_front(x+1,y);
        }
        if(y>0&&s[x][y-1]!='*'&&dist[x][y-1]>dist[x][y]+1){
            if(dist[x][y]-(y-c)<2*ld){
                dist[x][y-1]=dist[x][y]+1;
                q.emplace_back(x,y-1);
            }
        }
        if(y<m-1&&s[x][y+1]!='*'&&dist[x][y+1]>dist[x][y]+1){
            if(dist[x][y]+(y-c)<2*rd){
                dist[x][y+1]=dist[x][y]+1;
                q.emplace_back(x,y+1);
            }
        }
    }
    int ans=0;
    rep(i,n)rep(j,m){
        if(dist[i][j]!=inf)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
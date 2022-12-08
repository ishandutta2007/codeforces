#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;
const ll mod= 1e9+7;
const int inf=1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int n,m,k,s,dist[101010],d[101010][101];
vector<int> v[101010],f[101];

void bfs(int x){
  rep(i,n)dist[i]=inf;
  queue<int> q;
  rep(i,f[x].size()){
    dist[f[x][i]]=0;
    q.push(f[x][i]);
    }
  while(q.size()){
    int now=q.front();
    q.pop();
    for(auto e:v[now]){
      if(dist[e]==inf){
        dist[e]=dist[now]+1;
        q.push(e);
        }
      }
    }
  rep(i,n)d[i][x]=dist[i];
  }

int main(){
  cin>>n>>m>>k>>s;
  rep(i,n){
    int x;cin>>x;
    f[x-1].push_back(i);
    }
  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--;y--;
    v[x].push_back(y);
    v[y].push_back(x);
    }
  rep(i,k)bfs(i);
  rep(i,n){
    sort(d[i],d[i]+k);
    int ans=0;
    rep(j,s)ans+=d[i][j];
    cout<<ans<<" ";
    }
  
  return 0;
  }
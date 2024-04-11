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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(ll)(n);i++)
typedef pair<int,long long> pint;
typedef long long ll;
const ll mod= 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

vector<int> v[333],ans;
int dist[333][333];


void dfs(int x,int y,int pos,int par){
  if(pos==y)return;
  ans.push_back(pos);
  for(auto e:v[pos]){
    if(e==par)continue;
    if(dist[x][e]+dist[e][y]==dist[x][y]){
      dfs(x,y,e,pos);
      }
    }
  }
  
int main(){
  int n;cin>>n;
  rep(i,n)rep(j,n)
    if(i!=j)dist[i][j]=1000;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
    dist[a][b]=dist[b][a]=1;
    }
  int cnt=0;
  REP(i,1,n)if(v[i].size()==1)cnt++;
  int a[n+2];
  a[0]=0;
  rep(i,cnt){
    cin>>a[i+1];
    a[i+1]--;
    }
  a[cnt+1]=0;
  rep(i,n)rep(j,n)rep(k,n)
    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
  rep(i,cnt+1){
    dfs(a[i],a[i+1],a[i],-1);
    }
  ans.push_back(0);
  if(ans.size()==2*n-1){
    for(auto e:ans)cout<<e+1<<" ";
    }
else cout<<"-1";
  cout<<endl;
  return 0;
  }
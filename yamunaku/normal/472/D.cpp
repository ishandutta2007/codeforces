#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"YES"<<endl;
#define CNO cout<<"NO"<<endl;

typedef long long LL;
typedef long double LD;

struct edge{
  int from;
  int to;
  LL dist;
  edge(int f,int t,int d){
    from=f;
    to=t;
    dist=d;
  }
};

vector<vector<edge>> e;
vector<vector<LL>> ds;

void dfs(int now, int f, int p, LL d){
  ds[f][now]=ds[now][f]=d;
  for(auto &ed:e[now]){
    if(ed.to!=p){
      dfs(ed.to, f, now, d+ed.dist);
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<LL>> d(n,vector<LL>(n));
  rep(i,n){
    rep(j,n) cin >> d[i][j];
  }
  rep(i,n){
    rep(j,n){
      if(i==j){
        if(d[i][j]!=0){
          CNO;
          return 0;
        }
      }else{
        if(d[i][j]==0){
          CNO;
          return 0;
        }
        if(d[i][j]!=d[j][i]){
          CNO;
          return 0;
        }
      }
    }
  }
  e=vector<vector<edge>>(n);
  ds=vector<vector<LL>>(n,vector<LL>(n,LINF));
  rep(i,n) d[i][i]=0;
  vector<bool> added(n,false);
  added[0]=true;
  priority_queue<edge,vector<edge>,function<bool(edge,edge)>>
    heap([](const edge &a, const edge &b){return a.dist>b.dist;});
  repp(i,1,n) heap.push(edge(0,i,d[0][i]));
  while(!heap.empty()){
    edge now = heap.top();
    heap.pop();
    if(added[now.to]){
      if(ds[now.from][now.to]!=d[now.from][now.to]){
        CNO;
        return 0;
      }
      continue;
    }
    added[now.to]=true;
    e[now.from].push_back(edge(now.from,now.to,now.dist));
    e[now.to].push_back(edge(now.to,now.from,now.dist));
    dfs(now.to, now.to, -1, 0);
    rep(i,n){
      if(!added[i]) heap.push(edge(now.to,i,d[now.to][i]));
    }
  }
  CYES;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

vector<pair<int,pair<int,int>>> uf;

int root(int x){
  if(x==uf[x].first) return x;
  else return uf[x].first=root(uf[x].first);
}

void uni(int a,int b){
  a=root(a);
  b=root(b);
  if(a==b) return;
  if(uf[a].second.first>uf[b].second.first){
    uf[b].first=a;
    uf[a].second.second+=uf[b].second.second;
  }else if(uf[a].second.first<uf[b].second.first){
    uf[a].first=b;
    uf[b].second.second+=uf[a].second.second;
  }else{
    uf[b].first=a;
    uf[a].second.first++;
    uf[a].second.second+=uf[b].second.second;
  }
}

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> x(k);
  vector<bool> s(n,false);
  for(int i=0;i<k;i++) cin >> x[i],x[i]--,s[x[i]]=true;
  uf=vector<pair<int,pair<int,int>>>(n);
  for(int i=0;i<n;i++) uf[i]={i,{0,(s[i]?1:0)}};
  vector<pair<int,pair<int,int>>> e(m);
  int u,v,w;
  for(int i=0;i<m;i++){
    cin >> u >> v >> w;
    e[i]={w,{u-1,v-1}};
  }
  sort(e.begin(),e.end());
  for(int i=0;i<m;i++){
    uni(e[i].second.first,e[i].second.second);
    if(uf[root(e[i].second.first)].second.second==k){
      for(int j=0;j<k;j++){
        cout << e[i].first << " ";
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}
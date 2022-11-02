#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI dst;
VVI egs,egl;
priority_queue<pair<in,in> > q;
VVI pr;
VI tppr;
VI ord;
VI atm;
VI h;
in lca(in a, in b){
  if(h[a]<h[b])
    swap(a,b);
  for(in i=19;i>=0;--i){
    if(h[a]-(1<<i)>=h[b])
      a=pr[a][i];
  }
  assert(h[a]==h[b]);
  for(in i=19;i>=0;--i){
    if(pr[a][i]!=pr[b][i]){
      a=pr[a][i];
      b=pr[b][i];
    }
  }
  if(a!=b){
    a=pr[a][0];
    b=pr[b][0];
  }
  assert(a==b);
  return a;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,s;
  cin>>n>>m>>s;
  h.resize(n);
  --s;
  egs.resize(n);
  egl.resize(n);
  in ta,tb,tw;
  forn(z,m){
    cin>>ta>>tb>>tw;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egl[ta].PB(tw);
    egs[tb].PB(ta);
    egl[tb].PB(tw);
  }
  const in inf=1e18;
  dst.resize(n,inf);
  dst[s]=0;
  q.push(MP(-0,s));
  in u,d;
  while(!q.empty()){
    tie(d,u)=q.top();
    q.pop();
    d=-d;
    if(d!=dst[u])
      continue;
    ord.PB(u);
    forv(i,egs[u]){
      if(dst[egs[u][i]]>d+egl[u][i]){
	dst[egs[u][i]]=d+egl[u][i];
	q.push(MP(-dst[egs[u][i]],egs[u][i]));
      }
    }
  }
  assert(ord[0]==s);
  tppr.resize(n,-1);
  pr.resize(n,VI(20,-1));
  forv(i,ord){
    u=ord[i];
    if(u==s){
      assert(tppr[u]==-1);
      assert(i==0);
      pr[u][0]=s;
    }
    else{
      assert(tppr[u]!=-1);
      pr[u][0]=tppr[u];
    }
    h[u]=h[pr[u][0]]+1;
    for(in j=1;j<20;++j)
      pr[u][j]=pr[pr[u][j-1]][j-1];
    forv(j,egs[u]){
      if(dst[egs[u][j]]!=dst[u]+egl[u][j])
	continue;
      if(tppr[egs[u][j]]==-1){
	tppr[egs[u][j]]=u;
	continue;
      }
      tppr[egs[u][j]]=lca(tppr[egs[u][j]],tppr[u]);
    }
  }
  atm.resize(n);
  in rs=0;
  for(in i=sz(ord)-1;i>=1;--i){
    u=ord[i];
    ++atm[u];
    atm[pr[u][0]]+=atm[u];
    rs=max(rs,atm[u]);
  }
  cout<<rs<<endl;
  return 0;
}
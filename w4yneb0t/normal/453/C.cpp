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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,m;
vector<in> x;
vector<vector<in> > egs,cd;
in st=-1;
vector<in> pr;
queue<in> q;
vector<in> ans;
void ariv(in u){
  x[u]^=1;
  ans.PB(u);
  forv(i,cd[u]){
    ariv(cd[u][i]);
    if(u!=st || i+1!=sz(cd[u]) || x[u]==1){
      x[u]^=1;
      ans.PB(u);
    }
  }
  if(x[u]){
    ans.PB(pr[u]);
    x[pr[u]]^=1;
    ans.PB(u);
    x[u]^=1;
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  egs.resize(n);
  x.resize(n);
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(i,n){
    cin>>x[i];
    if(x[i])
      st=i;
  }
  if(st==-1){
    cout<<0<<endl;
    return 0;
  }
  cd.resize(n);
  pr.resize(n,-1);
  pr[st]=st;
  q.push(st);
  in u,v;
  while(!q.empty()){
    u=q.front();
    q.pop();
    forv(i,egs[u]){
      v=egs[u][i];
      if(pr[v]!=-1)
	continue;
      pr[v]=u;
      q.push(v);
      cd[u].PB(v);
    }
  }
  forv(i,x){
    if(pr[i]==-1 && x[i]==1){
      cout<<-1<<endl;
      return 0;
    }
  }
  ariv(st);
  cout<<sz(ans)<<"\n";
  forv(i,ans)
    cout<<ans[i]+1<<" ";
  cout<<"\n";
  return 0;
}
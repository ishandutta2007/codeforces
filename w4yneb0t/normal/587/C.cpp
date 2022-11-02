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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in p2(in a){
  return 1<<a;
}
VI h;
VI pr[18];
VVI ch[18];
set<pair<in,pair<in,pair<in,in> > > >::iterator it;
VI to;
void opt(set<pair<in,pair<in,pair<in,in> > > >& s, in cnt){
  to.clear();
  while(sz(s) && cnt){
    --cnt;
    it=s.begin();
    to.PB(it->first);
    if(it->second.second.second==sz(ch[it->second.first][it->second.second.first])){
      s.erase(it);
      continue;
    }
    s.insert(MP(ch[it->second.first][it->second.second.first][it->second.second.second],MP(it->second.first,MP(it->second.second.first,it->second.second.second+1))));
    s.erase(it);
  }
  printf("%d",sz(to));
  forv(i,to)
    printf(" %d",to[i]);
  printf("\n");
}
void ado(in u, in id, set<pair<in,pair<in,pair<in,in> > > >& s){
  if(sz(ch[id][u])==0)
    return;
  s.insert(MP(ch[id][u][0],MP(id,MP(u,1))));
}
void ad(in a, in u, set<pair<in,pair<in,pair<in,in> > > >& s){
  assert(h[a]>=h[u]);
  for(in i=17;i>=0;--i){
    if(h[a]-p2(i)>=h[u]){
      ado(a,i,s);
      a=pr[i][a];
    }
  }
}
in lca(in a, in b){
  if(h[a]<h[b])
    swap(a,b);
  for(in i=17;i>=0;--i){
    if(h[a]-p2(i)>=h[b])
      a=pr[i][a];
  }
  assert(h[a]==h[b]);
  for(in i=17;i>=0;--i){
    if(pr[i][a]!=pr[i][b]){
      a=pr[i][a];
      b=pr[i][b];
    }
  }
  if(a!=b){
    a=pr[0][a];
    b=pr[0][b];
  }
  assert(a==b);
  return a;
}
VVI egs;
void dfs(in u, in p, in th){
  h[u]=th;
  pr[0][u]=p;
  forv(i,egs[u]){
    if(egs[u][i]==p)
      continue;
    dfs(egs[u][i],u,th+1);
  }
}
set<pair<in,pair<in,pair<in,in> > > > s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,q;
  cin>>n>>m>>q;
  egs.resize(n);
  in ta,tb;
  forn(z,18)
    pr[z].resize(n);
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  h.resize(n);
  dfs(0,0,0);
  forn(z,18)
    ch[z].resize(n);
  forn(z,m){
    cin>>ta;
    --ta;
    ch[0][ta].PB(z+1);
  }
  forn(i,n)
    ch[0][i].resize(min(sz(ch[0][i]),10));
  for(in j=1;j<18;++j){
    forn(i,n){
      pr[j][i]=pr[j-1][pr[j-1][i]];
      ch[j][i]=ch[j-1][pr[j-1][i]];
      forv(k,ch[j-1][i])
	ch[j][i].PB(ch[j-1][i][k]);
      sort(all(ch[j][i]));
      ch[j][i].resize(min(sz(ch[j][i]),10));
    }
  }
  in tt;
  forn(z,q){
    cin>>ta>>tb>>tt;
    --ta;
    --tb;
    in u=lca(ta,tb);
    s.clear();
    ad(ta,u,s);
    ad(tb,u,s);
    ado(u,0,s);
    opt(s,tt);
  }
  return 0;
}
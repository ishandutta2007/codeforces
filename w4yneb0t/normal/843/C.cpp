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
VVI egs;
VI blw;
VI lrgc;
in gentot(const in& u, const in& pr){
  blw[u]=1;
  lrgc[u]=0;
  in tup;
  in ts=sz(egs[u]);
  forn(i,ts){
    tup=egs[u][i];
    if(tup==pr)
      continue;
    blw[u]+=gentot(tup,u);
    lrgc[u]=max(lrgc[u],blw[tup]);
  }
  return blw[u];
}
in n;
VI solx,soly,solyy;
in curpt;
void findbot(in cur, in pr, in cent, in gol){
  bool hasg=0;
  if(cur==gol)
    hasg=1;
  in v;
  forv(i,egs[cur]){
    v=egs[cur][i];
    if(v==gol){
      hasg=1;
    }
    if(v!=pr){
      findbot(v,cur,cent,gol);
    }
  }
  if(!hasg){
    solx.PB(cent);
    soly.PB(curpt);
    solyy.PB(cur);
    curpt=cur;
    solx.PB(cur);
    soly.PB(pr);
    solyy.PB(gol);
  }
}
void gen(in bpt){
  if(sz(lrgc)==0){
    lrgc.resize(sz(egs));
    blw.resize(sz(egs));
  }
  gentot(bpt,bpt);
  in msz=blw[bpt];
  VI c;
  forn(i,n){
    if(blw[i]*2>=msz && lrgc[i]*2<=msz){
      c.PB(i);
    }
  }
  assert(sz(c)>=1 && sz(c)<=2);
  in u,v;
  forv(i,c){
    u=c[i];
    forv(j,egs[u]){
      v=egs[u][j];
      if(v==c[0] || (sz(c)==2 && v==c[1]))
	continue;
      curpt=v;
      findbot(v,u,u,v);
      soly.PB(curpt);
      solx.PB(u);
      solyy.PB(v);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  egs.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  gen(0);
  cout<<sz(solx)<<"\n";
  forv(i,solx){
    cout<<solx[i]+1<<" "<<soly[i]+1<<" "<<solyy[i]+1<<"\n";
  }
  return 0;
}
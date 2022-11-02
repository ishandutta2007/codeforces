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
in n,m,k;
struct eg{
  in typ;
  in leg;
  in dest;
  eg(in a=0, in b=0, in c=0){
    typ=a;leg=b;dest=c;
  }
};
vector<vector<eg> > egs;
vector<in> dt;
in reqtr=0;
const in inf=1000000000000000000LL;
struct loc{
  in dest,leg,typ;
  loc(in a=0, in b=0, in c=0){typ=a;leg=b;dest=c;}
  bool operator<(const loc cp)const{
    if(leg!=cp.leg)
      return leg>cp.leg;
    if(typ!=cp.typ)
      return typ;
    return dest<cp.dest;
  }
};
priority_queue<loc> pq;
vector<int> vis;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m>>k;
  egs.resize(n);
  vis.resize(n);
  dt.resize(n,inf);
  in tx,ty,tt;
  forn(i,m){
    cin>>tx>>ty>>tt;
    tx--;
    ty--;
    egs[tx].PB(eg(0,tt,ty));
    egs[ty].PB(eg(0,tt,tx));
  }
  forn(i,k){
    cin>>tx>>tt;
    tx--;
    egs[0].PB(eg(1,tt,tx));
  }
  dt[0]=0;
  pq.push(loc(0,0,0));
  loc tp;
  while(!pq.empty()){
    tp=pq.top();
    pq.pop();
    if(vis[tp.dest])
      continue;
    dt[tp.dest]=tp.leg;
    vis[tp.dest]=1;
    if(tp.typ)
      reqtr++;
    forv(i,egs[tp.dest]){
      eg& teg=egs[tp.dest][i];
      pq.push(loc(teg.typ,teg.leg+tp.leg,teg.dest));
    }
  }
  cout<<k-reqtr<<endl;
  return 0;
}
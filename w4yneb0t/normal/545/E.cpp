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
in n;
struct eg{
  in dest,id,wt;
  eg(in a=0, in b=0, in c=0){dest=a;id=b;wt=c;}
};
struct gl{
  in id,dt;
  gl(in a=0, in b=0){id=a;dt=b;}
  bool operator<(const gl cp)const{
    if(dt!=cp.dt)
      return dt>cp.dt;
    return id<cp.id;
  }
};
vector<vector<eg> > egs;
VI dist,prid;
priority_queue<gl> q;
in sm=0;
VI sol;
VI egw;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>n>>m;
  dist.resize(n,1000000000000000000LL);
  prid.resize(n);
  egs.resize(n);
  in ta,tb,tw;
  forn(z,m){
    cin>>ta>>tb>>tw;
    ta--;
    tb--;
    egs[ta].PB(eg(tb,z+1,tw));
    egs[tb].PB(eg(ta,z+1,tw));
    egw.PB(tw);
  }
  in st;
  cin>>st;
  st--;
  dist[st]=0;
  prid[st]=-1;
  q.push(gl(st,0));
  gl tp,tt;
  while(!q.empty()){
    tp=q.top();
    q.pop();
    if(dist[tp.id]!=tp.dt)continue;
    if(prid[tp.id]!=-1){
      sm+=egw[prid[tp.id]-1];
      sol.PB(prid[tp.id]);
    }
    forv(i,egs[tp.id]){
      tt.id=egs[tp.id][i].dest;
      tt.dt=egs[tp.id][i].wt+tp.dt;
      if(dist[tt.id]<tt.dt)continue;
      if(dist[tt.id]>tt.dt)q.push(tt);
      dist[tt.id]=tt.dt;
      prid[tt.id]=egs[tp.id][i].id;
    }
  }
  cout<<sm<<endl;
  forv(i,sol)
    cout<<sol[i]<<" ";
  cout<<endl;
  return 0;
}
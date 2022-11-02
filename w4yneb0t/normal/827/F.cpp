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
struct eg{
  in ot,l,r;
  eg(in pot, in pl, in pr){
    ot=pot;
    l=pl;
    r=pr;
  }
  bool operator<(const eg cp)const{
    if(l!=cp.l)
      return l<cp.l;
    if(r!=cp.r)
      return r<cp.r;
    return ot<cp.ot;
  }
};
const in inf=2e9;
in bst=inf;
in n,m;
vector<vector<eg> > egs;
priority_queue<tuple<in,in,in> > pq;
vector<map<in,in> > optim;
VI nxtcand;
void ad(in u, in tarr, in tlv){
  pq.push(tuple<in,in,in>(-tarr,-tlv,u));
}
void proc(in u, in tarr, in tlv){
  if(nxtcand[u]==sz(egs[u]))
    return;
  eg& e=egs[u][nxtcand[u]];
  if(e.l>tlv)
    return;
  ++nxtcand[u];
  if(e.r>=tarr)
    ad(e.ot,max(e.l+1,tarr+1),e.r+1);
  proc(u,tarr,tlv);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  egs.resize(2*n);
  optim.resize(2*n);
  nxtcand.resize(2*n);
  in ta,tb,l,r;
  forn(zz,m){
    cin>>ta>>tb>>l>>r;
    --ta;
    --tb;
    if(!(r==l+1 && l%2==1)){
      egs[ta].PB(eg(tb+n,l+l%2,r-1-(r-1)%2));
      egs[tb].PB(eg(ta+n,l+l%2,r-1-(r-1)%2));
    }
    if(!(r==l+1 && l%2==0)){
      egs[ta+n].PB(eg(tb,l+(l+1)%2,r-1-r%2));
      egs[tb+n].PB(eg(ta,l+(l+1)%2,r-1-r%2));
    }
  }
  forv(i,egs)
    sort(all(egs[i]));
  optim[0][0]=1;
  optim[0][2]=-1;
  pq.push(tuple<in,in,in>(-0,-0,0));
  in u,tarr,tlv;
  while(!pq.empty()){
    tie(tarr,tlv,u)=pq.top();
    pq.pop();
    tarr=-tarr;
    tlv=-tlv;
    if(u==n-1 || u==2*n-1){
      bst=min(bst,tarr);
    }
    proc(u,tarr,tlv);
  }
  if(bst==inf)
    cout<<-1<<"\n";
  else
    cout<<bst<<"\n";
  return 0;
}
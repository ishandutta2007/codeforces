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
void fl(){
  cout<<-1<<endl;
  exit(0);
}
VVI egs,egw,egp;
VI curw,minw,totl,upegl;
void mk(in u, in cw, in cp){
  forv(i,egs[u]){
    mk(egs[u][i],egw[u][i],egp[u][i]);
    curw[u]+=curw[egs[u][i]];
    minw[u]+=minw[egs[u][i]];
  }
  if(minw[u]>cp)
    fl();
  if(curw[u]>cp){
    in tr=curw[u]-cp;
    totl[u]=tr;
    curw[u]-=tr;
  }
  curw[u]+=cw;
  in crd=min(cp-minw[u],cw-1);
  minw[u]+=cw-crd;
}
void pusd(in u, in cp){
  totl[u]+=cp;
  curw[u]-=cp;
  in cn;
  forv(i,egs[u]){
    cn=min(totl[u],curw[egs[u][i]]-minw[egs[u][i]]);
    pusd(egs[u][i],cn);
    totl[u]-=cn;
  }
  upegl[u]=totl[u];
}
VI inx,iny;
in n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  egs.resize(n);
  egw=egp=egs;
  curw=minw=totl=upegl=VI(n);
  inx.resize(n-1);
  iny.resize(n-1);
  in tw,tp;
  forn(z,n-1){
    cin>>inx[z]>>iny[z]>>tw>>tp;
    --inx[z];
    --iny[z];
    egs[inx[z]].PB(iny[z]);
    egw[inx[z]].PB(tw);
    egp[inx[z]].PB(tp);
  }
  mk(0,1,1e16);
  pusd(0,0);
  egs=VVI(n);
  cout<<n<<"\n";
  forv(z,inx){
    cout<<(inx[z]+1)<<" "<<(iny[z]+1)<<" "<<(egw[inx[z]][sz(egs[inx[z]])]-upegl[iny[z]])<<" "<<(egp[inx[z]][sz(egs[inx[z]])]-upegl[iny[z]])<<"\n";
    egs[inx[z]].PB(iny[z]);
  }
  return 0;
}
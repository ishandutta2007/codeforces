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
struct pt;
vector<pt> pepr;
struct pt{
  in x,y;
  pt(in a=0, in b=0){x=a;y=b;}
  pt operator-(const pt cp)const{
    return pt(x-cp.x,y-cp.y);
  }
  in operator^(const pt cp)const{
    return x*cp.y-y*cp.x;
  }
  bool operator<(const pt cp)const{
    in cr=((*this-pepr[0])^(cp-pepr[0]));
    if(cr!=0)return cr>0;
    if(y==pepr[0].y && y==cp.y)return x<cp.x;
    return y<cp.y;
  }
};
vector<pt> wrp;
bool isin(pt q){
  if(q.y>=wrp.back().y)
    return 0;
  assert(q.y>wrp[0].y);
  in mn=0;
  in mx=sz(wrp)-1;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(wrp[md].y<q.y)
      mn=md;
    else
      mx=md;
  }
  return ((wrp[mx]-wrp[mn])^(q-wrp[mn]))>0;
}
vector<pt> ee;
void wrap(){
  ee.clear();
  in mid=0;
  forv(i,pepr){
    if(pepr[i].y<pepr[mid].y || (pepr[i].y==pepr[mid].y && pepr[i].x<pepr[mid].x))
      mid=i;
  }
  if(mid!=0)swap(pepr[0],pepr[mid]);
  sort(pepr.begin()+1,pepr.end());
  ee.PB(pepr[0]);
  pt ppr,pr,cr;
  for(in i=1;i<sz(pepr);++i){
    while(1){
      if(sz(ee)==1)
	break;
      ppr=ee[sz(ee)-2];
      pr=ee[sz(ee)-1];
      cr=pepr[i];
      if(((pr-ppr)^(cr-pr))>0)
	break;
      ee.pop_back();
    }
    ee.PB(pepr[i]);
  }
}
in n,m;
vector<pt> hasmx;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in junk;
  cin>>n>>m>>junk>>junk;
  hasmx.resize(n);
  forn(i,n)
    cin>>hasmx[i].x>>hasmx[i].y;
  pepr.resize(m);
  forn(i,m)
    cin>>pepr[i].x>>pepr[i].y;
  pepr.PB(pt(0,0));
  in mxx=0;
  in mxy=0;
  forn(i,m){
    mxx=max(mxx,pepr[i].x);
    mxy=max(mxy,pepr[i].y);
  }
  pepr.PB(pt(0,mxy));
  pepr.PB(pt(mxx,0));
  wrap();
  in lc0=-1;
  forv(i,ee){
    if(ee[i].x==0 && ee[i].y==0)
      lc0=i;
  }
  assert(lc0!=-1);
  assert(sz(ee)>=4);
  for(in i=(lc0+1)%sz(ee);(i+1)%sz(ee)!=lc0;i=(i+1)%sz(ee))
    wrp.PB(ee[i]);
  assert(wrp[0].y==0);
  assert(wrp[0].x==mxx);
  forv(i,hasmx){
    if(!isin(hasmx[i])){
      cout<<"Max"<<endl;
      return 0;
    }
  }
  cout<<"Min"<<endl;
  return 0;
}
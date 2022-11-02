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

double ab(double a){
  return a<0?-a:a;
}
struct pt;
vector<pt> pepr;
const double EPS=1e-22;
struct pt{
  double x,y;
  in id;
  pt(double a=0, double b=0, in i=0){x=a;y=b;id=i;}
  pt operator-(const pt cp)const{
    return pt(x-cp.x,y-cp.y);
  }
  double operator^(const pt cp)const{
    return x*cp.y-y*cp.x;
  }
  bool operator<(const pt cp)const{
    double cr=((*this-pepr[0])^(cp-pepr[0]));
    if(ab(cr)>EPS)return cr>0;
    return x<cp.x;
  }
};
vector<pt> ee;
void wrap(){
  in mid=0;
  forv(i,pepr){
    if(pepr[i].x<pepr[mid].x || (pepr[i].x==pepr[mid].x && pepr[i].y<pepr[mid].y))
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
      if(((pr-ppr)^(cr-pr))>=-EPS)
	break;
      ee.pop_back();
    }
    ee.PB(pepr[i]);
  }
  while(1){
    if(sz(ee)<=1)
      break;
    pr=ee[sz(ee)-2];
    cr=ee[sz(ee)-1];
    if(cr.y<ee[0].y && cr.y<pr.y)
      break;
    ee.pop_back();
  }
}
set<pair<in,in> > opst;
in n;
map<in,VI> mx,my;
VI px,py;
VI eli;
set<pair<in,in> > isok;
VI ops;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  in r,s;
  eli.resize(n,0);
  forn(i,n){
    cin>>r>>s;
    px.PB(r);
    py.PB(s);
    mx[r].PB(i);
    my[s].PB(i);
  }
  fors(i,mx){
    in mni=i->second[0];
    forv(j,i->second){
      if(py[i->second[j]]>py[mni])
	mni=i->second[j];
    }
    forv(j,i->second){
      if(py[i->second[j]]!=py[mni])
	eli[i->second[j]]=1;
    }
  }
  fors(i,my){
    in mni=i->second[0];
    forv(j,i->second){
      if(px[i->second[j]]>px[mni])
	mni=i->second[j];
    }
    forv(j,i->second){
      if(px[i->second[j]]!=px[mni])
	eli[i->second[j]]=1;
    }
  }
  forv(i,px){
    if(eli[i])continue;
    if(opst.find(MP(px[i],py[i]))!=opst.end())continue;
    opst.insert(MP(px[i],py[i]));
    pepr.PB(pt(1.0/px[i],1.0/py[i],i));
  }
  wrap();
  forv(i,ee){
    isok.insert(MP(px[ee[i].id],py[ee[i].id]));
  }
  forv(i,px){
    if(eli[i])continue;
    if(isok.find(MP(px[i],py[i]))!=isok.end())
      ops.PB(i+1);
  }
  forv(i,ops)
    cout<<ops[i]<<" ";
  cout<<"\n";
  return 0;
}
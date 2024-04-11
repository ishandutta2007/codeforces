#include<iostream>
#include<iomanip>
#include<cmath>
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
struct pt{
  double x,y;
  pt(double a=0, double b=0){
    x=a;
    y=b;
  }
};
double sq(double a){
  return a*a;
}
double dst(const pt& a, const pt& b){
  return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}
void rd(pt& p){
  cin>>p.x>>p.y;
}
double sm=0;
vector<pair<double,in> > da,db;
pt pa,pb,pr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  rd(pa);
  rd(pb);
  rd(pr);
  in n;
  cin>>n;
  pt tp;
  double t;
  forn(z,n){
    rd(tp);
    t=dst(tp,pr);
    da.PB(MP(dst(tp,pa)-t,z));
    db.PB(MP(dst(tp,pb)-t,z));
    sm+=2*t;
  }
  da.PB(MP(0,-1));
  db.PB(MP(0,-1));
  sort(all(da));
  sort(all(db));
  double bst=1e18;
  forn(i,min(3LL,sz(da))){
    forn(j,min(3LL,sz(db))){
      if(da[i].second==db[j].second)
	continue;
      if(da[i].second==-1 && db[j].second==-1)
	continue;
      bst=min(bst,da[i].first+db[j].first);
    }
  }
  cout<<setprecision(15);
  cout<<sm+bst<<endl;
  return 0;
}
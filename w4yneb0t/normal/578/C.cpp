#include<iostream>
#include<iomanip>
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
struct ln{
  double m,b;
  ln(double a=0, double c=0){   //start,slope
    b=a;
    m=c;
  }
  bool operator<(const ln cp)const{
    return m<cp.m;
  }
};
double ints(ln& A, ln& B){
  return (B.b-A.b)/(A.m-B.m);
}
double vat(ln& A, double& x){
  return A.b+A.m*x;
}
const double INF=1e30;
double bst=INF;
void proc(ln& l1, ln& l2, double& x){
  bst=min(bst,vat(l1,x)+vat(l2,x));
}
struct lns{
  vector<ln> v;
  vector<ln> actl;
  vector<double> actx;
  void adl(ln a){
    double cx=ints(a,actl.back());
    while(cx<actx.back()){
      actx.pop_back();
      actl.pop_back();
      cx=ints(a,actl.back());
    }
    actx.PB(cx);
    actl.PB(a);
  }
  void gen(){
    sort(all(v));
    actx.PB(-INF);
    actl.PB(v[0]);
    for(in i=1;i<sz(v);++i)
      adl(v[i]);
  }
};
lns l1,l2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in csm=0;
  in tp;
  l1.v.PB(ln(0,0));
  l2.v.PB(ln(0,0));
  forn(i,n){
    cin>>tp;
    csm+=tp;
    l1.v.PB(ln(csm,-(i+1)));
    l2.v.PB(ln(-csm,i+1));
  }
  l1.gen();
  l2.gen();
  in p1=1;
  in p2=1;
  double cx1,cx2;
  while(p1<sz(l1.actx) || p2<sz(l2.actx)){
    cx1=(p1==sz(l1.actx)?INF:l1.actx[p1]);
    cx2=(p2==sz(l2.actx)?INF:l2.actx[p2]);
    if(cx1<cx2){
      proc(l1.actl[p1-1],l2.actl[p2-1],cx1);
      ++p1;
    }
    else{
      proc(l1.actl[p1-1],l2.actl[p2-1],cx2);
      ++p2;
    }
  }
  cout<<setprecision(15)<<bst<<endl;
  return 0;
}
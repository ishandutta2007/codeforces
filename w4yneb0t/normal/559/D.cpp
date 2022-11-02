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
const in ckct=80;
const in mx=200009;
in n;
VI x,y;
vector<double> negp2;
double cpr(double x1, double y1, double x2, double y2){
  return x1*y2-x2*y1;
}
in rgcd(in a, in b){
  if(b==0)
    return a;
  return rgcd(b,a%b);
}
in gcd(in a, in b){
  if(a<0)a=-a;
  if(b<0)b=-b;
  return rgcd(a,b);
}
vector<double> ear,eb;        //float precision paranoia
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  negp2.resize(mx);
  negp2[0]=1;
  ear=eb=vector<double>(ckct+10,0);
  for(in i=1;i<mx;i++)
    negp2[i]=negp2[i-1]/2.0;
  cin>>n;
  x=y=VI(n);
  forn(i,n)
    cin>>x[i]>>y[i];
  double totprobbad=n+n*(n-1)/2+1;
  totprobbad*=negp2[n];
  double totprobfact=1/(1-totprobbad);
  forn(i,n){
    in kt,j;
    in rightside;
    double prob;
    double probbad=negp2[n];
    double arcont,bcont;
    for(j=(i-1<0?i-1+n:i-1),kt=0;j!=i && kt<ckct;++kt,j=(j-1>=0?j-1:j-1+n)){
      rightside=kt;
      prob=negp2[rightside+2]-probbad;
      arcont=cpr(x[j],y[j],x[i],y[i])*0.5;
      bcont=gcd(x[i]-x[j],y[i]-y[j]);
      prob*=totprobfact;
      ear[kt]+=arcont*prob;
      eb[kt]+=bcont*prob;
    }
  }
  double totear=0;
  double toteb=0;
  for(in i=sz(ear)-1;i>=0;--i){
    totear+=ear[i];
    toteb+=eb[i];
  }
  cout<<setprecision(20)<<totear+1-toteb/2.0<<endl;
  return 0;
}
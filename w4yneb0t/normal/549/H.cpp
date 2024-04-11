#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<iomanip>
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
const double eps=1e-12;
pair<double,double> mkd(double a, double b, double ofs){
  vector<double> vt;
  vt.PB((a-ofs)*(b-ofs));
  vt.PB((a+ofs)*(b-ofs));
  vt.PB((a-ofs)*(b+ofs));
  vt.PB((a+ofs)*(b+ofs));
  sort(all(vt));
  return MP(vt[0],vt[3]);
}
double a,b,c,d;
bool ispo(double md){
  pair<double,double> tt=mkd(a,d,md);
  pair<double,double> tp=mkd(b,c,md);
  if(tt.first>tp.second || tp.first>tt.second)
    return 0;
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>c>>d;
  double mn=0;
  double mx=10+1e9;
  double md;
  while(mx>mn+eps && mx>mn*(1+eps)){
    md=(mx+mn)*0.5;
    if(ispo(md))
      mx=md;
    else
      mn=md;
  }
  cout<<setprecision(30)<<mn<<endl;
  return 0;
}
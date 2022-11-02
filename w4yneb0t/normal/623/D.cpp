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
struct nd{
  double crv;
  double lwr;
  double mp;
  nd(double a=0, double b=0, double c=0){
    crv=a;
    lwr=b;
    mp=c;
  }
  bool operator<(const nd cp)const{
    return crv<cp.crv;
  }
};
priority_queue<nd> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  double totexp=0;
  double pgsf=1;
  double bp;
  forn(i,n){
    cin>>bp;
    bp=1-bp/100.0;
    pgsf*=1-bp;
    q.push(nd((1-bp*bp)/(1-bp),bp,bp));
  }
  totexp+=n*pgsf;
  nd tp;
  in tnsf=n;
  while(!q.empty()){
    tp=q.top();
    q.pop();
    ++tnsf;
    totexp+=tnsf*pgsf*(tp.crv-1);
    pgsf*=tp.crv;
    tp.lwr*=tp.mp;
    if(tp.lwr>1e-50)
      q.push(nd((1-tp.lwr*tp.mp)/(1-tp.lwr),tp.lwr,tp.mp));
  }
  cout<<setprecision(15)<<totexp<<endl;
  return 0;
}
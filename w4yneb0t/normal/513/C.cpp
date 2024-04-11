#include<iomanip>
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
in n;
in l[5];
in r[5];
double rg(in w){
  return (r[w]-l[w]+1);
}
double pro(in winr, in sec, in val){
  in stb=val;
  if(winr>sec)
    stb++;
  if(stb>r[winr])
    return 0;
  if(stb<l[winr])stb=l[winr];
  double k=(r[winr]-stb+1)/rg(winr);
  forn(i,n){
    if(i!=winr && i!=sec){
      in mxb=val;
      if(i<sec)
	mxb--;
      if(mxb<l[i])
	return 0;
      if(mxb>r[i])mxb=r[i];
      k*=(mxb-l[i]+1)/rg(i);
    }
  }
  return k;
}
double prw(in w, in v){
  if(v<l[w] || v>r[w])return 0;
  double sf=1/rg(w);
  double tp=0;
  forn(i,n){
    if(i!=w)
      tp+=pro(i,w,v);
  }
  return sf*tp;
}
double prb(in v){
  double rt=0;
  forn(i,n){
    rt+=prw(i,v);
  }
  return rt;
}
double ev=0;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  forn(i,n){
    cin>>l[i]>>r[i];
  }
  for(in i=1;i<=10000;i++){
    ev+=i*prb(i);
  }
  cout<<setprecision(15)<<ev<<endl;
  return 0;
}
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
in ab(in a){
  return a<0?-a:a;
}
VI x,y;
in gl;
VI tkn;
bool isp(in md){
  tkn.resize(sz(x));
  forv(i,tkn)
    tkn[i]=0;
  in lf;
  forv(i,y){
    lf=md-ab(y[i]-gl);
    forv(j,x){
      if(!tkn[j] && ab(x[j]-y[i])<=lf){
	tkn[j]=1;
	break;
      }
    }
  }
  forv(i,tkn)
    if(!tkn[i])
      return 0;
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k>>gl;
  x.resize(n);
  forn(i,n)
    cin>>x[i];
  y.resize(k);
  forn(i,k)
    cin>>y[i];
  sort(all(x));
  sort(all(y));
  in mn=-1;
  in mx=3e9;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(isp(md))
      mx=md;
    else
      mn=md;
  }
  cout<<mx<<endl;
  return 0;
}
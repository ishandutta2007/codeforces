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
const in inf=1e18;
in n;
VI c,d;
VVI cd;
VVI bcy,bcn;
VI ncd,pr;
void cc(in u){
  bcn[u][0]=0;
  bcn[u][1]=c[u];
  bcy[u][0]=inf;
  bcy[u][1]=d[u];
  in msf=1;
  in cu;
  in tt;
  
  forv(z,cd[u]){
    cu=cd[u][z];
    cc(cu);
    tt=ncd[cu];
    assert(msf+tt<sz(bcn[u]));
    for(in i=msf+tt;i>=0;--i){
      for(in j=max(1LL,i-msf);j<=tt && j<=i;++j){
	bcn[u][i]=min(bcn[u][i],bcn[u][i-j]+bcn[cu][j]);
	bcy[u][i]=min(bcy[u][i],bcy[u][i-j]+bcy[cu][j]);
      }
    }
    msf+=tt;
  }
  forv(i,bcn[u]){
    bcy[u][i]=min(bcy[u][i],bcn[u][i]);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in b;
  cin>>n>>b;
  c.resize(n);
  d.resize(n);
  cd.resize(n);
  bcy.resize(n);
  bcn.resize(n);
  ncd.resize(n);
  pr.resize(n);
  forn(i,n){
    cin>>c[i]>>d[i];
    d[i]=c[i]-d[i];
    if(i){
      cin>>pr[i];
      --pr[i];
      cd[pr[i]].PB(i);
    }
  }
  for(in i=n-1;i>=0;--i){
    ncd[i]++;
    if(i)
      ncd[pr[i]]+=ncd[i];
  }
  forn(i,n){
    bcy[i].resize(ncd[i]+1,inf);
    bcn[i].resize(ncd[i]+1,inf);
  }
  cc(0);
  in bst=0;
  forv(i,bcy[0]){
    if(bcy[0][i]<=b)
      bst=max(bst,i);
  }
  forv(i,bcn[0]){
    if(bcn[0][i]<=b)
      bst=max(bst,i);
  }
  cout<<bst<<endl;
  return 0;
}
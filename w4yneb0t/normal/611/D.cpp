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
const in mdl=1000000007LL;
in n;
string nb;
vector<vector<int> > fdf;
in fd(in a, in b){
  assert(b>=a);
  if(b==n)
    return a;
  int& tp=fdf[a][b];
  if(tp!=-1)
    return tp;
  if(nb[a]!=nb[b])
    return tp=a;
  return tp=fd(a+1,b+1);
}
VVI wys,wysup;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cin>>nb;
  fdf=vector<vector<int> >(n,vector<int>(n,-1));
  wys=wysup=VVI(n,VI(n+1,0));
  in surlf,surrt;
  in cdf,cdnu;
  for(in rt=0;rt<=n-1;++rt){
    wysup[rt][rt+1]=0;
    for(in lf=rt;lf>=0;--lf){
      if(lf==0){
	wys[rt][lf]=1;
      }
      else{
	if(nb[lf]=='0'){
	  wys[rt][lf]=0;
	}
	else{
	  surrt=lf-1;
	  surlf=surrt-(rt-lf);
	  wys[rt][lf]=wysup[surrt][max(surlf+1,0LL)];
	  if(surlf>=0){
	    cdf=fd(surlf,lf);
	    cdnu=cdf+(lf-surlf);
	    if(cdf<lf && nb[cdf]<nb[cdnu]){
	      wys[rt][lf]+=wys[surrt][surlf];
	      wys[rt][lf]%=mdl;
	    }
	  }
	}
      }
      wysup[rt][lf]=(wysup[rt][lf+1]+wys[rt][lf])%mdl;
    }
  }
  cout<<wysup[n-1][0]<<endl;
  return 0;
}
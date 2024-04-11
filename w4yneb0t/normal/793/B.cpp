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
void yes(){
  cout<<"YES"<<endl;
  exit(0);
}
vector<string> bd;
VVI hv;
void ppl(in x, in y, in m){
  in cy=y;
  while(cy>=0 && bd[x][cy]!='*'){
    hv[x][cy]|=m;
    --cy;
  }
  cy=y;
  while(cy<sz(bd[x]) && bd[x][cy]!='*'){
    hv[x][cy]|=m;
    ++cy;
  }
  in cx=x;
  while(cx>=0 && bd[cx][y]!='*'){
    hv[cx][y]|=m;
    --cx;
  }
  cx=x;
  while(cx<sz(bd) && bd[cx][y]!='*'){
    hv[cx][y]|=m;
    ++cx;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  hv.resize(n,VI(m));
  bd.resize(n);
  in xs,ys,xt,yt;
  forn(i,n){
    cin>>bd[i];
    forn(j,m){
      if(bd[i][j]=='S'){
	xs=i;
	ys=j;
      }
      if(bd[i][j]=='T'){
	xt=i;
	yt=j;
      }
    }
  }
  ppl(xs,ys,1);
  ppl(xt,yt,2);
  in msk=0;
  forn(i,n){
    msk=0;
    forn(j,m){
      if(bd[i][j]=='*')
	msk=0;
      msk|=hv[i][j];
      if(msk==3)
	yes();
    }
  }
  forn(j,m){
    msk=0;
    forn(i,n){
      if(bd[i][j]=='*')
	msk=0;
      msk|=hv[i][j];
      if(msk==3)
	yes();
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
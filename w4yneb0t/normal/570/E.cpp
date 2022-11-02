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
in n,m;
vector<string> bd;
VVI wys[2];
VVI mvs={{1,0},{1,-1},{0,0},{0,-1}};
void upd(in sw, in nw, in lfsm, in rtsm){
  in ni,nj,nri,nrj;
  forv(i,wys[nw])
    forv(j,wys[nw][i])
    wys[nw][i][j]=0;
  forn(i,m){
    forn(j,m){
      if(wys[sw][i][j]==0)continue;
      forv(k,mvs){
	ni=i+mvs[k][0];
	nj=j+mvs[k][1];
	nri=lfsm+1-ni;
	nrj=rtsm-1-nj;
	if(ni>=0 && ni<=nj && nj<m && nri>=0 && nri<=nrj && nrj<n && bd[nri][ni]==bd[nrj][nj])
	  wys[nw][ni][nj]=(wys[nw][ni][nj]+wys[sw][i][j])%mdl;
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  bd.resize(n);
  forn(i,n)
    cin>>bd[i];
  if(bd[0][0]!=bd[n-1][m-1]){
    cout<<0<<endl;return 0;
  }
  forn(i,2)
    wys[i].resize(m,VI(m,0));
  wys[0][0][m-1]=1;
  in sw=0;
  in nw=0;
  in smi,smj;
  for(in ccl=0;ccl*2<n+m-3;++ccl){
    sw=ccl%2;
    nw=!sw;
    upd(sw,nw,ccl,n+m-2-ccl);
    smi=ccl+1;
    smj=n+m-2-ccl-1;
  }
  in rs=0;
  if((n+m)%2){
    forn(i,m){
      forn(j,m){
	if(i<=j && smi-i<=smj-j && j-i+(smj-j)-(smi-i)==1)
	  rs+=wys[nw][i][j];
      }
    }
  }
  else{
    forn(i,m)
      rs+=wys[nw][i][i];
  }
  rs%=mdl;
  cout<<rs<<endl;
  return 0;
}
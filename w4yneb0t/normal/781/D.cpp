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
const in mx=9;
const in btl=60;
in p2(in a){
  return 1LL<<a;
}
struct tvr{
  in fw[mx*btl][mx];
  in rw[mx*btl][mx];
  bool is0=1;
  tvr(){
    forn(i,mx*btl){
      forn(j,mx){
	fw[i][j]=rw[i][j]=0;
      }
    }
  }
  void stb(in a, in b){
    fw[a][b/btl]|=p2(b%btl);
    rw[b][a/btl]|=p2(a%btl);
    is0=0;
  }
  tvr operator*(const tvr cp){
    tvr ret;
    forn(i,500){
      forn(j,500){
	forn(k,mx){
	  if(fw[i][k]&cp.rw[j][k])
	    ret.stb(i,j);
	}
      }
    }
    return ret;
  }
  void opt(){
    forn(i,2){
      forn(j,2){
	if(fw[i][0]&p2(j))
	  cout<<1;
	else
	  cout<<0;
      }
      cout<<endl;
    }
    forn(i,2){
      forn(j,2){
	if(rw[i][0]&p2(j))
	  cout<<1;
	else
	  cout<<0;
      }
      cout<<endl;
    }
    cout<<endl;
  }
};
void lrg(){
  cout<<-1<<endl;
  exit(0);
}
tvr slv[61][2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  in ta,tb,tt;
  forn(z,m){
    cin>>ta>>tb>>tt;
    --ta;
    --tb;
    slv[0][tt].stb(ta,tb);
  }
  if(slv[0][0].is0){
    cout<<0<<endl;
    return 0;
  }
  in tmx=-1;
  for(in i=1;i<=60;++i){
    slv[i][0]=slv[i-1][0]*slv[i-1][1];
    slv[i][1]=slv[i-1][1]*slv[i-1][0];
    if(slv[i][0].is0){
      tmx=i-1;
      break;
    }
  }
  if(tmx==-1){
    lrg();
  }
  in ssf=p2(tmx);
  tvr mn=slv[tmx][0];
  tvr tp;
  in tad=1;
  while(tmx>0){
    tp=mn*slv[tmx-1][tad];
    if(tp.is0){
      --tmx;
      continue;
    }
    mn=tp;
    ssf+=p2(tmx-1);
    --tmx;
    tad=!tad;
  }
  if(ssf>1000000000000000000LL)
    lrg();
  cout<<ssf<<endl;
  return 0;
}
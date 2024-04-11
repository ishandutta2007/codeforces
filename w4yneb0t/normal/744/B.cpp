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
in p2(in a){
  return 1LL<<a;
}
VI qr;
VVI ans[2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  forn(z,2)
    ans[z].resize(10,VI(n,1e10));
  forn(i,10){
    forn(z,2){
      qr.clear();
      forn(k,n){
	if((!!(k&p2(i)))==z)
	  qr.PB(k);
      }
      if(!qr.empty()){
	cout<<sz(qr)<<endl;
	forv(i,qr)
	  cout<<qr[i]+1<<" ";
	cout<<endl;
	forn(a,n)
	  cin>>ans[z][i][a];
      }	
    }
  }
  cout<<-1<<endl;
  forn(i,n){
    in cmn=1e10;
    forn(z,2){
      forn(j,10){
	if((!!(i&p2(j)))!=z)
	  cmn=min(cmn,ans[z][j][i]);
      }
    }
    cout<<cmn<<" ";
  }
  cout<<endl;
  return 0;
}
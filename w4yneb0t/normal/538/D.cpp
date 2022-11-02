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
vector<string> res,mbd,sbd;
in n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  mbd.resize(n);
  sbd.resize(n,string(n,'.'));
  res.resize(2*n-1,string(2*n-1,'x'));
  res[n-1][n-1]='o';
  forn(i,n){
    cin>>mbd[i];
    forn(j,n)
      if(mbd[i][j]=='o')
	sbd[i][j]='o';
  }
  forn(i,n){
    forn(j,n){
      if(mbd[i][j]=='o'){
	forn(a,n){
	  forn(b,n){
	    if(mbd[a][b]=='.')
	      res[n-1+a-i][n-1+b-j]='.';
	  }
	}
      }
    }
  }
  forn(i,n){
    forn(j,n){
      if(sbd[i][j]=='o'){
	forn(a,n){
	  forn(b,n){
	    if(sbd[a][b]=='.' && res[n-1+a-i][n-1+b-j]=='x')
	      sbd[a][b]='x';
	  }
	}
      }
    }
  }
  if(sbd==mbd){
    cout<<"YES"<<endl;
    forv(i,res)
      cout<<res[i]<<endl;
  }
  else
    cout<<"NO"<<endl;
  return 0;
}
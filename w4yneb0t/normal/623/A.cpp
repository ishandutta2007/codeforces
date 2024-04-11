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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VVI ps;
string sol;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  ps.resize(n,VI(n,0));
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    ps[ta][tb]=ps[tb][ta]=1;
  }
  sol=string(n,'b');
  forn(i,n){
    bool fd=0;
    forn(j,n){
      if(i==j)
	continue;
      if(!ps[i][j]){
	fd=1;
	tb=j;
      }
    }
    if(!fd)
      continue;
    forn(j,n){
      if(i!=j){
	if(!ps[i][j])
	  sol[j]='c';
      }
      if(tb!=j){
	if(!ps[tb][j])
	  sol[j]='a';
      }
    }
  }
  bool isok=1;
  forn(i,n){
    forn(j,n){
      if(i==j)
	continue;
      if(ps[i][j]!=(!((sol[i]=='a' && sol[j]=='c')||(sol[i]=='c' && sol[j]=='a'))))
	isok=0;
    }
  }
  if(!isok){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl<<sol<<endl;
  return 0;
}
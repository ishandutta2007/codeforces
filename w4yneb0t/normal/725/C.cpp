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
void mkpath(string gl, in i1, in i2){
  vector<string> sol(2,string(13,'x'));
  if((i2-i1)%2==1){
    in oo=(i2-i1-1)/2;
    in sloc=12-oo;
    in nxt=i1;
    for(in i=sloc;i<13;++i){
      sol[0][i]=gl[nxt%27];
      ++nxt;
    }
    for(in i=12;i>sloc;--i){
      sol[1][i]=gl[nxt%27];
      ++nxt;
    }
    assert(gl[nxt%27]==sol[0][sloc]);
    ++nxt;
    for(in i=sloc-1;i>=0;--i){
      sol[0][i]=gl[nxt%27];
      ++nxt;
    }
    forn(i,sloc+1){
      sol[1][i]=gl[nxt%27];
      ++nxt;
    }
  }
  else{
    in oo=(i2-i1)/2-1;
    in sloc=12-oo;
    in nxt=i1;
    for(in i=sloc;i<13;++i){
      sol[0][i]=gl[nxt%27];
      ++nxt;
    }
    for(in i=12;i>=sloc;--i){
      sol[1][i]=gl[nxt%27];
      ++nxt;
    }
    assert(gl[nxt%27]==sol[0][sloc]);
    ++nxt;
    for(in i=sloc-1;i>=0;--i){
      sol[0][i]=gl[nxt%27];
      ++nxt;
    }
    forn(i,sloc){
      sol[1][i]=gl[nxt%27];
      ++nxt;
    }
  }
  cout<<sol[0]<<endl<<sol[1]<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string gl;
  cin>>gl;
  forv(i,gl){
    forn(j,i){
      if(gl[i]==gl[j]){
	if(j+1==i)
	  cout<<"Impossible"<<endl;
	else
	  mkpath(gl,j,i);
	return 0;
      }
    }
  }
  return 0;
}
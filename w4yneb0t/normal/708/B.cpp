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
void imp(){
  cout<<"Impossible\n";
  exit(0);
}
in a00,a01,a10,a11;
bool isp(in n0, in n1){
  if(n0+n1==0)
    return 0;
  if(n0*(n0-1)/2!=a00)
    return 0;
  if(n1*(n1-1)/2!=a11)
    return 0;
  in tt=n0*n1;
  if(a01+a10!=tt)
    return 0;
  while(n0+n1>0){
    if(a01>=n1 && n0>0){
      --n0;
      a01-=n1;
      cout<<0;
    }
    else{
      assert(n1>0 && a10>=n0);
      --n1;
      a10-=n0;
      cout<<1;
    }
  }
  cout<<"\n";
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>a00>>a01>>a10>>a11;
  in n0=0;
  in n1=0;
  while(n0*(n0-1)/2<a00)
    ++n0;
  if(n0*(n0-1)/2!=a00)
    imp();
  while(n1*(n1-1)/2<a11)
    ++n1;
  if(n1*(n1-1)/2!=a11)
    imp();
  forn(t0,2){
    forn(t1,2){
      if(isp(n0+t0,n1+t1))
	return 0;
    }
  }
  imp();
  return 0;
}
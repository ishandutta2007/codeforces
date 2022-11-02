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
void fl(){
  cout<<"NO"<<endl;
  exit(0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in cl=0;
  string dir;
  in ds;
  forn(zz,n){
    cin>>ds>>dir;
    if(dir=="East" || dir=="West"){
      if(cl==0 || cl==20000)
	fl();
      continue;
    }
    if(dir=="South"){
      cl+=ds;
      if(cl>20000)
	fl();
      continue;
    }
    if(dir=="North"){
      cl-=ds;
      if(cl<0)
	fl();
      continue;
    }
    assert(0);
  }
  if(cl!=0)
    fl();
  cout<<"YES"<<endl;
  return 0;
}
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
in isg[109];
in n;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  char tp;
  forn(i,n){
    cin>>tp;
    isg[i]=(tp=='*');
  }
  forn(st,n){
    for(in jp=1;jp<=n;jp++){
      in okc=0;
      for(in i=st;i<n && i<=(st+4*jp);i+=jp)
	okc+=isg[i];
      if(okc==5){
	cout<<"yes"<<endl;
	return 0;
      }
    }
  }
  cout<<"no"<<endl;
  return 0;
}
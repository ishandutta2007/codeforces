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
int main(){
  in maxd[2];
  in d[2];
  in c[2];
  cin>>maxd[0]>>maxd[1]>>d[0]>>d[1]>>c[0]>>c[1];
  forn(a1,2){
    forn(a2,2){
      forn(a3,2){
	if((d[a1]+c[a2]<=maxd[a3]) && (d[!a1]<=maxd[!a3]) && (c[!a2]<=maxd[!a3])){
	  cout<<"YES"<<endl;
	  return 0;
	}
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
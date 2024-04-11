#include<iostream>
#include<sstream>
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  forn(i,1001){
    if(i%8==0){
      string sc;
      stringstream is;
      is<<i;
      sc=is.str();
      in j=0;
      in cp=0;
      while(cp<sz(s) && j<sz(sc)){
	if(s[cp]==sc[j])
	  j++;
	cp++;
      }
      if(j==sz(sc)){
	cout<<"YES"<<endl<<sc<<endl;
	return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  in bs=n-1+n-k;
  in s,c;
  forn(z,k){
    cin>>s;
    cin>>c;
    if(c!=1){
      forn(zz,s-1)
	cin>>c;
      continue;
    }
    for(in z=2;z<=s;++z){
      cin>>c;
      if(c!=z){
	cout<<bs-2*(z-2)<<endl;
	return 0;
      }
    }
    cout<<bs-2*(s-1)<<endl;
    return 0;
  }
  return 0;
}
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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI c;
vector<string> mar[2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  c.resize(n);
  forn(z,2)
    mar[z].resize(n);
  forn(i,n)
    cin>>c[i];
  forn(i,n){
    cin>>mar[0][i];
    mar[1][i]=mar[0][i];
    reverse(all(mar[1][i]));
  }
  const in inf=1e18;
  VI bst(2);
  VI nb(2);
  bst[0]=0;
  bst[1]=c[0];
  for(in i=1;i<n;++i){
    nb[0]=nb[1]=inf;
    forn(o,2){
      forn(z,2){
	if(mar[o][i-1]<=mar[z][i]){
	  nb[z]=min(nb[z],bst[o]+z*c[i]);
	}
      }
    }
    bst=nb;
  }
  in r=min(bst[0],bst[1]);
  if(r==inf)
    cout<<-1<<endl;
  else
    cout<<r<<endl;
  return 0;
}
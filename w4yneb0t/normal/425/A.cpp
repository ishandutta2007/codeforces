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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,k;
vector<in> a;
vector<in> inside,outside;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  in best=-1000000000000000LL;
  in tsm;
  forn(r,n){
    forn(l,r+1){
      tsm=0;
      inside.clear();
      outside.clear();
      forn(i,n){
	if(i<=r && i>=l){
	  inside.PB(a[i]);
	  tsm+=a[i];
	}
	else
	  outside.PB(a[i]);
      }
      sort(all(inside));
      sort(all(outside));
      reverse(all(outside));
      for(in i=0;i<k && i<sz(inside) && i<sz(outside) && inside[i]<outside[i];i++){
	tsm+=outside[i];
	tsm-=inside[i];
      }
      if(tsm>best)
	best=tsm;
    }
  }
  cout<<best<<endl;
  return 0;
}
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
vector<VVI> ofs;
VI p,a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ofs.resize(3,VVI(3));
  in n;
  cin>>n;
  p=a=b=VI(n);
  forn(i,n)
    cin>>p[i];
  forn(i,n)
    cin>>a[i];
  forn(i,n)
    cin>>b[i];
  forn(i,n){
    ofs[a[i]-1][b[i]-1].PB(p[i]);
  }
  forn(i,3){
    forn(j,3){
      sort(all(ofs[i][j]));
      reverse(all(ofs[i][j]));
    }
  }
  in m;
  cin>>m;
  const in inf=1e18;
  forn(z,m){
    in mpr=inf;
    in t;
    cin>>t;
    --t;
    forn(i,3){
      forn(j,3){
	if(i==t || j==t){
	  if(!ofs[i][j].empty())
	    mpr=min(mpr,ofs[i][j].back());
	}
      }
    }
    if(mpr==inf){
      cout<<-1<<" ";
      continue;
    }
    cout<<mpr<<" ";
    forn(i,3){
      forn(j,3){
	if(!ofs[i][j].empty() && ofs[i][j].back()==mpr)
	  ofs[i][j].pop_back();
      }
    }
  }
  cout<<"\n";
  return 0;
}
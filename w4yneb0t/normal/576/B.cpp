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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI v,p,t;
vector<VVI> ccs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  p.resize(n);
  forn(i,n){
    cin>>p[i];
    --p[i];
  }
  ccs.resize(n+3);
  v.resize(n);
  forn(i,n){
    if(v[i])
      continue;
    in u=i;
    t.clear();
    do{
      t.PB(u);
      v[u]=1;
      u=p[u];
    }while(u!=i);
    ccs[sz(t)].PB(t);
  }
  if(!ccs[1].empty()){
    cout<<"YES\n";
    in x=ccs[1][0][0];
    ++x;
    for(in i=1;i<=n;++i){
      if(i!=x)
	cout<<x<<" "<<i<<"\n";
    }
    return 0;
  }
  if(!ccs[2].empty()){
    bool ok=1;
    forv(i,ccs){
      if(!ccs[i].empty() && i%2==1)
	ok=0;
    }
    if(ok){
      cout<<"YES\n";
      in x=ccs[2][0][0];
      in y=ccs[2][0][1];
      ++x;
      ++y;
      cout<<x<<" "<<y<<"\n";
      forv(i,ccs){
	for(in j=(i==2);j<sz(ccs[i]);++j){
	  forv(k,ccs[i][j]){
	    if(k%2)
	      cout<<x<<" "<<ccs[i][j][k]+1<<"\n";
	    else
	      cout<<y<<" "<<ccs[i][j][k]+1<<"\n";
	  }
	}
      }
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;
}
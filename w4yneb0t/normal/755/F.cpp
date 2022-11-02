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
VI lts;
VI vis,p;
VI ps;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  lts.resize(n+1);
  vis.resize(n,0);
  p.resize(n);
  forn(i,n){
    cin>>p[i];
    --p[i];
  }
  forn(i,n){
    if(vis[i])
      continue;
    in u=i;
    in c=0;
    while(!vis[u]){
      ++c;
      vis[u]=1;
      u=p[u];
    }
    assert(c>1);
    ++lts[c];
  }
  in tk=k;
  in lft=0;
  in cl;
  in mx=0;
  forn(i,n+1){
    forn(j,lts[i]){
      cl=i-(i%2);
      if(tk*2>=cl){
	tk-=cl/2;
	mx+=cl;
	lft+=i%2;
	continue;
      }
      mx+=tk*2;
      tk=0;
    }
  }
  while(tk && lft){
    --lft;
    --tk;
    ++mx;
  }
  in rk=k;
  k=min(k,n-k);
  ps.resize(k+1);
  ps[0]=1;
  forn(i,n+1){
    if(!lts[i])
      continue;
    for(in st=0;st<i;++st){
      lft=0;
      for(in j=st;j<=k;j+=i){
	if(ps[j])
	  lft=lts[i];
	else{
	  if(lft){
	    ps[j]=1;
	    --lft;
	  }
	}
      }
    }
  }
  if(ps[k])
    cout<<rk;
  else
    cout<<rk+1;
  cout<<" "<<mx<<endl;
  return 0;
}
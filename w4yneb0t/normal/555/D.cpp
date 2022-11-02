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
VI x;
in fpv(in a){
  return (upper_bound(all(x),a)-x.begin())-1;
}
in fnx(in a){
  return lower_bound(all(x),a)-x.begin();
}
in qa(in i, in l){
  in u=fpv(x[i]+l);
  l-=x[u]-x[i];
  i=u;
  in dr=0;
  in v;
  in d,nt;
  while(1){
    if(!dr){
      v=fnx(x[u]-l);
      if(v==u)
	return u;
      d=x[u]-x[v];
      nt=l/d;
      l%=d;
      if(nt%2){
	u=v;
	dr=1;
      }
      continue;
    }
    v=fpv(x[u]+l);
    if(v==u)
      return u;
    d=x[v]-x[u];
    nt=l/d;
    l%=d;
    if(nt%2){
      u=v;
      dr=0;
    }
  }
}
VI mx;
map<in,in> dcd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  x.resize(n);
  forn(i,n){
    cin>>x[i];
    dcd[x[i]]=i+1;
  }
  mx=x;
  sort(all(x));
  in t;
  in l;
  forn(z,m){
    cin>>t>>l;
    t=mx[t-1];
    cout<<dcd[x[qa(fpv(t),l)]]<<"\n";
  }
  return 0;
}
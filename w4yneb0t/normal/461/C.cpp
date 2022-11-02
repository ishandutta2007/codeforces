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
in n,qq;
in zero=0;
in one=1;
in lend,rend;
vector<in> fw,av;
void ad(in x, in a){
  av[x]+=a;
  while(x<n){
    fw[x]+=a;
    x|=(x+1);
  }
}
in sm(in x){
  in r=0;
  while(x>=0){
    r+=fw[x];
    x&=(x+1);
    x--;
  }
  return r;
}
in srang(in a, in b){
  return sm(b-1)-sm(a-1);
}
in transf(in a){
  return zero+one*a;
}
void fold(in a){
  if(a-lend>rend-a){
    zero=a;
    one=-1;
    for(in i=a;i<rend;i++){
      ad(a-1-(i-a),av[i]);
    }
    rend=a;
  }
  else{
    zero=a;
    one=1;
    for(in i=lend;i<a;i++){
      ad(a-1-(i-a),av[i]);
    }
    lend=a;
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>qq;
  fw.resize(n,0);
  av.resize(n,0);
  forn(i,n)
    ad(i,1);
  lend=0;
  rend=n;
  in typ,l,r;
  forn(zz,qq){
    cin>>typ>>l;
    if(typ==2){
      cin>>r;
      l=transf(l);
      r=transf(r);
      if(l>r)
	swap(l,r);
      cout<<srang(l,r)<<"\n";
    }
    else{
      fold(transf(l));
    }
  }
  return 0;
}
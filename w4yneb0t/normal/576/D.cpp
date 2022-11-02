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
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<in> VI;
typedef vector<VI> VVI;
const ll ls=60;
in n;
ll p2(ll a){
  return 1LL<<a;
}
struct mt{
  VVL a;
  VVL b;
  void ini(){
    a.resize(n,VL((n+ls-1)/ls));
    b=a;
  }
  void ad(in x, in y){
    a[y][x/ls]|=p2(x%ls);
    b[x][y/ls]|=p2(y%ls);
  }
  mt operator*(const mt& cp)const{
    mt r;
    r.ini();
    forn(i,n){
      forn(j,n){
	forv(k,a[i]){
	  if(a[i][k]&cp.b[j][k])
	    r.ad(j,i);
	}
      }
    }
    return r;
  }
};
struct ft{
  in a,b,d;
  ft(in x=0, in y=0, in z=0){
    a=x;
    b=y;
    d=z;
  }
  bool operator<(const ft cp)const{
    return d<cp.d;
  }
};
vector<ft> fts;
mt pw(mt a, in d){
  mt r;
  r.ini();
  forn(i,n)
    r.ad(i,i);
  for(in i=30;i>=0;--i){
    r=r*r;
    if(d&p2(i))
      r=r*a;
  }
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>n>>m;
  fts.PB(ft(n-1,n-1,0));
  fts.PB(ft(n-1,n-1,in(1e9)+1000));
  in ta,tb,td;
  forn(z,m){
    cin>>ta>>tb>>td;
    --ta;
    --tb;
    fts.PB(ft(ta,tb,td));
  }
  sort(all(fts));
  in pvd=0;
  mt tfm,sf,tpw,tck;
  sf.ini();
  sf.ad(0,0);
  tfm.ini();
  forv(i,fts){
    tpw=pw(tfm,fts[i].d-pvd);
    tck=tpw*sf;
    if(!(tck.a[n-1][0]&p2(0))){
      sf=tpw*sf;
      pvd=fts[i].d;
      tfm.ad(fts[i].a,fts[i].b);
      continue;
    }
    in mn=0;
    in mx=fts[i].d-pvd;
    in md;
    while(mx-mn>1){
      md=(mn+mx)/2;
      tpw=pw(tfm,md);
      tck=tpw*sf;
      if(!(tck.a[n-1][0]&p2(0)))
	mn=md;
      else
	mx=md;
    }
    cout<<mx+pvd<<"\n";
    return 0;
  }
  cout<<"Impossible\n";
  return 0;
}
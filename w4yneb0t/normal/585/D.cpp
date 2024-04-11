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
const in inf=5e9;
in bv;
in sol;
in n;
vector<string> sym={"MW","LW","LM"};
map<in, pair<in,in> > fd;
VVI c;
map<in, pair<in,in> >::iterator it;
VI p3;
void fs(in nx, in ed, VI& sc, in msk){
  if(nx==ed){
    it=fd.find((sc[2]-sc[0])*inf+sc[2]-sc[1]);
    if(it!=fd.end() && it->second.first+sc[2]>bv){
      bv=it->second.first+sc[2];
      sol=msk+it->second.second;
    }
    return;
  }
  forn(i,3){
    forn(j,3)
      if(j!=i)
	sc[j]+=c[nx][j];
    fs(nx+1,ed,sc,msk+p3[nx]*i);
    forn(j,3)
      if(j!=i)
	sc[j]-=c[nx][j];
  }
}
void gen(in nx, VI& sc, in msk){
  if(nx==n){
    it=fd.find((sc[0]-sc[2])*inf+sc[1]-sc[2]);
    if(it==fd.end() || it->second.first<sc[2])
      fd[(sc[0]-sc[2])*inf+sc[1]-sc[2]]=MP(sc[2],msk);
    return;
  }
  forn(i,3){
    forn(j,3)
      if(j!=i)
	sc[j]+=c[nx][j];
    gen(nx+1,sc,msk+p3[nx]*i);
    forn(j,3)
      if(j!=i)
	sc[j]-=c[nx][j];
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  p3.resize(30);
  p3[0]=1;
  for(in i=1;i<30;++i)
    p3[i]=3*p3[i-1];
  cin>>n;
  c.resize(n,VI(3));
  forn(i,n){
    forn(j,3)
      cin>>c[i][j];
  }
  VI sc(3);
  gen((n+1)/2,sc,0);
  bv=-inf;
  fs(0,(n+1)/2,sc,0);
  if(bv==-inf){
    cout<<"Impossible"<<endl;
    return 0;
  }
  forn(i,n){
    cout<<sym[sol%3];
    cout<<endl;
    sol/=3;
  }
  return 0;
}
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
const in mx=85;
const in inf=1e9;
in bst[mx][mx][mx];
VVI egs,dif;
in bs(in st, in ed, in k){
  in& tp=bst[st][ed][k];
  if(tp!=-1)
    return tp;
  if(k==0)
    return tp=0;
  if(ed==st+1 || ed==st-1)
    return tp=inf;
  in gl,gd;
  tp=inf;
  forv(i,egs[st]){
    gl=egs[st][i];
    if((ed-gl)*(gl-st)<=0)
      continue;
    gd=dif[st][i];
    tp=min(tp,bs(gl,st,k-1)+gd);
    tp=min(tp,bs(gl,ed,k-1)+gd);
  }
  return tp;
}
in n,k;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  egs.resize(n+1);
  dif.resize(n+1);
  forn(i,mx){
    forn(j,mx){
      forn(z,mx){
	bst[i][j][z]=-1;
      }
    }
  }
  in ct;
  cin>>ct;
  forn(zz,ct){
    in ta,tb,tc;
    cin>>ta>>tb>>tc;
    egs[ta].PB(tb);
    dif[ta].PB(tc);
  }
  in r=inf;
  for(in st=1;st<=n;++st){
    r=min(r,bs(st,0,k-1));
    r=min(r,bs(st,n+1,k-1));
  }
  if(r==inf)
    cout<<-1<<endl;
  else
    cout<<r<<endl;
  return 0;
}
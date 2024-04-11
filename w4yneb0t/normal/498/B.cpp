#include<iostream>
#include<iomanip>
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
vector<double> pte[2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,t;
  //n=t=50;
  cin>>n>>t;
  in sw=1;
  in nw=0;
  forn(z,2)
    pte[z]=vector<double>(t+1,0);
  pte[nw][0]=1;
  double sm=0;
  in mt;
  double p;
  const double EPS=1e-15;
  forn(z,n){
    swap(nw,sw);
    forn(i,t+1)
      pte[nw][i]=0;/*
    p=48+rand()%5;
    mt=1+rand()%50;*/
    cin>>p>>mt;
    p/=100;
    double rmg=1;
    double mkh=1;
    forn(i,mt-1){
      rmg-=mkh*p;
      mkh*=1-p;
      if(mkh<EPS)
        mkh=0;
    }
    mkh*=p;
    for(in i=1;i<=t;++i){
      pte[nw][i]=pte[nw][i-1]*(1-p);
      pte[nw][i]+=pte[sw][i-1]*p;
      if(i>=mt)
	pte[nw][i]-=pte[sw][i-mt]*mkh;
      if(pte[nw][i]<EPS)
        pte[nw][i]=0;
    }
    forn(i,t+1){
      if(i>=mt)
        pte[nw][i]+=pte[sw][i-mt]*rmg;
      sm+=pte[nw][i];
    }
  }
  cout<<setprecision(15)<<sm<<endl;
  return 0;
}
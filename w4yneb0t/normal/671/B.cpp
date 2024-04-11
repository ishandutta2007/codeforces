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
in cd(VI& ofs, in k){
  if(sz(ofs)==0)
    return 0;
  sort(all(ofs));
  reverse(all(ofs));
  in n=sz(ofs);
  ofs.PB(0);
  in dd,tt;
  forn(i,n){
    dd=ofs[i]-ofs[i+1];
    tt=dd*(i+1);
    if(tt<=k){
      k-=tt;
      continue;
    }
    return ofs[i]-k/(i+1);
  }
  return 0;
}
VI ofs1,ofs2;
VI mar;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  mar.resize(n);
  in sm=0;
  forn(i,n){
    cin>>mar[i];
    sm+=mar[i];
  }
  in ds=sm/n;
  in dl=ds;
  if(sm%n)
    ++dl;
  in tofl=0;
  in tofs=0;
  forn(i,n){
    if(mar[i]>dl){
      tofl+=mar[i]-dl;
      ofs1.PB(mar[i]-dl);
    }
    if(mar[i]<ds){
      tofs+=ds-mar[i];
      ofs2.PB(ds-mar[i]);
    }
  }
  in l;
  if(tofl<=k)
    l=0;
  else
    l=cd(ofs1,k);
  in s;
  if(tofs<=k)
    s=0;
  else
    s=cd(ofs2,k);
  cout<<(l+s+(dl-ds))<<endl;
  return 0;
}
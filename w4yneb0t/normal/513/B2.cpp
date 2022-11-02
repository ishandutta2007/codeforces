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
in n;
in blu(in above, in below){
  if(above==0)return 0;
  return 1LL<<(above-1);
}
set<in> avb;
void opt(in bl, in lst){
  if(lst==n){
    vector<in> nbs;
    for(set<in>::iterator i=avb.begin();i!=avb.end();++i)
      nbs.PB(*i);
    reverse(all(nbs));
    forv(i,nbs)
      cout<<nbs[i]<<(i==sz(nbs)-1?"":" ");
    cout<<endl;
    return;
  }
  in blsf=0;
  vector<in> wtf;
  for(set<in>::iterator rm=avb.begin();rm!=avb.end();++rm){
    wtf.PB(*rm);
  }
  forv(wat,wtf){
    in tp=wtf[wat];
    if(tp<lst)
      continue;
    avb.erase(tp);
    in abv=0;
    in blw=0;
    for(set<in>::iterator i=avb.begin();i!=avb.end();++i){
      if((*i)>tp)
	abv++;
      else
	blw++;
    }
    in ad=blu(abv,blw);
    if(ad+blsf>bl || tp==n){
      cout<<tp<<" ";
      opt(bl-blsf,tp);
      return;
    }
    else{
      blsf+=ad;
      avb.insert(tp);
    }
  }
}
in m;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m;
  forn(i,n)
    avb.insert(i+1);
  opt(m-1,-1);
  return 0;
}
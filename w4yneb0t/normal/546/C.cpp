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
set<pair<VI,VI> > osn;
VI s1,s2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  cin>>n;
  in tc;
  forn(i,n){
    cin>>tc;
    s1.PB(tc);
  }
  cin>>n;
  forn(i,n){
    cin>>tc;
    s2.PB(tc);
  }
  in mvc=0;
  pair<VI,VI> tpr;
  while(sz(s1) && sz(s2)){
    mvc++;
    tpr=MP(s1,s2);
    if(osn.count(tpr)){cout<<-1<<endl;break;}
    osn.insert(tpr);
    if(s1[0]>s2[0]){
      s1.PB(s2[0]);
      s1.PB(s1[0]);
    }
    else{
      s2.PB(s1[0]);
      s2.PB(s2[0]);
    }
    forn(i,sz(s1)-1)
      s1[i]=s1[i+1];
    s1.pop_back();
    forn(i,sz(s2)-1)
      s2[i]=s2[i+1];
    s2.pop_back();
  }
  if(sz(s1)==0)
    cout<<mvc<<" 2"<<endl;
  if(sz(s2)==0)
    cout<<mvc<<" 1"<<endl;
  return 0;
}
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
in ods,evs;
in n,k;
bool lastoneisstan(){
  return ((n-k)%2==1);
}
bool lastonewins(){
  in gloflast=(lastoneisstan()?0:1);
  in lwins0=(gloflast==0);
  in lwins1=(k%2==gloflast);
  in lsturns=(n-k)/2;
  if(!lwins0 && !lwins1)
    return 1;
  if(lwins0 && !lwins1){
    if(ods<=lsturns)
      return 0;
    return 1;
  }
  if(!lwins0 && lwins1){
    if(evs<=lsturns)
      return 0;
    return 1;
  }
  if(lwins0 && lwins1){
    in ctrn=0;
    if((n-k)%2==0)
      ctrn=1;
    for(in i=n;i>k;i--){
      if(ods>evs)
	swap(ods,evs);
      if(ctrn==0)
	evs--;
      else
	ods--;
      ctrn=!ctrn;
    }
    if(ods>evs)
      swap(ods,evs);
    if(ods<=0)
      return 0;
    return 1;
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  ods=evs=0;
  in wa;
  forn(i,n){
    cin>>wa;
    if(wa%2==0)
      evs++;
    else
      ods++;
  }
  if(n==k){
    if(ods%2==1)
      cout<<"Stannis";
    else
      cout<<"Daenerys";
    cout<<endl;
    return 0;
  }
  cout<<((lastonewins()^lastoneisstan()^1)?"Stannis":"Daenerys")<<endl;
  return 0;
}
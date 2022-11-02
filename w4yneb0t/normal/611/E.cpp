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
bool ispo(in frit, in cba, in cbb, in cbc){
  in tt=min(cbc,frit);
  cbc-=tt;
  frit-=tt;
  if(cbc)
    return 0;
  cba-=min(frit,cba);
  tt=min(frit,cbb);
  cbb-=tt;
  frit-=tt;
  cba-=min(frit,cba);
  if(cba || cbb)
    return 0;
  return 1;
}
in rsl=0;
VI msk(3);
VI fri(3,0);
VI crim,nucrim;
VI act;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  forn(i,3)
    cin>>msk[i];
  sort(all(msk));
  crim.resize(n);
  forn(i,n)
    cin>>crim[i];
  sort(all(crim));
  if(sz(crim) && crim.back()>msk[0]+msk[1]+msk[2]){
    cout<<-1<<endl;
    return 0;
  }
  while(sz(crim) && crim.back()>msk[1]+msk[2]){
    ++rsl;
    crim.pop_back();
  }
  while(sz(crim) && crim.back()>msk[0]+msk[2]){
    ++rsl;
    ++fri[0];
    crim.pop_back();
  }
  while(sz(crim) && (crim.back()>msk[0]+msk[1] && crim.back()>msk[2])){
    ++rsl;
    ++fri[1];
    crim.pop_back();
  }
  in frit=0;
  if(msk[0]+msk[1]>msk[2]){
    while(sz(crim) && crim.back()>msk[2]){
      ++rsl;
      ++fri[2];
      crim.pop_back();
    }
  }
  while(sz(crim) && crim.back()>msk[0]+msk[1]){
    ++rsl;
    ++frit;
    crim.pop_back();
  }
  act.resize(sz(crim),1);
  for(in i=sz(act)-1;i>=0;--i){
    forn(x,3){
      if(crim[i]<=msk[x] && fri[x]){
	--fri[x];
	act[i]=0;
	break;
      }
    }
  }
  forv(i,crim){
    if(act[i])
      nucrim.PB(crim[i]);
  }
  crim=nucrim;
  fri=VI(3,0);
  in cba=0;
  in cbb=0;
  in cbc=0;
  forv(i,crim){
    if(crim[i]<=msk[0]){
      ++cba;
      continue;
    }
    if(crim[i]<=msk[1]){
      ++cbb;
      continue;
    }
    ++cbc;
  }
  in mn=-1;
  in mx=300000;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    in nucba=cba;
    in nucbb=cbb;
    in nucbc=cbc;
    in nufrit=frit;
    in tns=md;
    in tt=min(nucbc,tns);
    nucbc-=tt;
    nufrit+=tt;
    tns-=tt;
    tt=min(nucbb,tns);
    nucbb-=tt;
    nufrit+=tt;
    tns-=tt;
    tt=min(nucba,tns);
    nucba-=tt;
    nufrit+=tt;
    tns-=tt;
    if(ispo(nufrit,nucba,nucbb,nucbc))
      mx=md;
    else
      mn=md;
  }
  cout<<(mx+rsl)<<endl;
  return 0;
}
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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
// f(i,j) = (ps[j]-ps[i])^2 + (j-i)^2
vector<in> ps;
in n;
struct prr{
  in loc;
  prr(in a=0){
    loc=a;
  }
  in mil()const{
    return ps[loc];
  }
  bool operator<(const prr cp)const{
    if(mil()!=cp.mil())
      return mil()<cp.mil();
    return loc<cp.loc;
  }
};
set<prr> act;
in d;
in sq(in a){
  return a*a;
}
in dit(in a, in b){
  return sq(a-b)+sq(ps[a]-ps[b]);
}
typedef set<prr>::iterator sit;
void proc(in id){
  act.insert(id);
  sit cit=act.find(id);
  sit up=cit;
  sit dn=cit;/*
  cout<<"here ";
  for(sit cc=act.begin();cc!=act.end();++cc){
    cout<<cc->loc<<" ";
  }
  cout<<endl;*/
  while(up!=act.end() && sq(up->mil()-cit->mil())<=d){
    up++;
  }
  while(sq(dn->mil()-cit->mil())<=d){
    if(dn==act.begin()){
      break;
    }
    dn--;
  }/*
  cout<<dn->loc<<" "<<cit->loc<<" ";
  if(up==act.end())
    cout<<"end";
  else
    cout<<up->loc;
    cout<<endl;*/
  while(dn!=up){
    if(dn==cit){
      dn++;
      continue;
    }
    //cout<<dn->loc<<" "<<id<<" "<<dit(dn->loc,id)<<endl;
    if(dit(dn->loc,id)<d)
      d=dit(dn->loc,id);
    dn++;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  ps.resize(n);
  forn(i,n){
    cin>>ps[i];
    if(i>0)
      ps[i]+=ps[i-1];
  }
  d=1000000000000000000LL;
  in reg=0;
  in leg=0;
  while(reg<n){
    proc(reg);
    reg++;
    while(sq(leg-reg)>d){
      act.erase(leg++);
    }
  }
  cout<<d<<endl;
  return 0;
}
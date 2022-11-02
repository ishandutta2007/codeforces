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
pair<in,in> ask(in id){
  cout<<"? "<<id<<endl;
  in v,nxt;
  cin>>v>>nxt;
  return MP(v,nxt);
}
in rnd(){
  // just making the code longer so you can't copy it and generate a hack
  in c=rand();
  const in mdl=1237845;
  c%=mdl;
  c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c+=rand();c^=rand();c^=rand();c^=rand();c^=rand();
  return c;
}
vector<pair<in,in> > vid;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  srand(123);
  in n,st,x;
  cin>>n>>st>>x;
  vid.PB(MP(ask(st).first,st));
  forn(z,1000){
    in id=1+rnd()%n;
    vid.PB(MP(ask(id).first,id));
  }
  sort(all(vid));
  st=0;
  while(st<sz(vid)-1 && vid[st+1].first<=x)
    ++st;
  in cv=vid[st].first;
  st=vid[st].second;
  while(cv<x){
    st=ask(st).second;
    if(st==-1){
      cout<<"! "<<-1<<endl;
      return 0;
    }
    cv=ask(st).first;
  }
  cout<<"! "<<cv<<endl;
  return 0;
}
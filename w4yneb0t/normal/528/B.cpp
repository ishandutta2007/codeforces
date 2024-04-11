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
in n;
in bsf=0;
struct ev{
  in typ,val,loc;
  ev(in a=0, in b=0, in c=0){typ=a;val=b;loc=c;}
  bool operator<(const ev cp)const{
    if(loc!=cp.loc)return loc<cp.loc;
    if(typ!=cp.typ)return typ<cp.typ; // typ 1 is add, typ 2 is check
    return val<cp.val;
  }
};
set<ev> evs;
void proc(ev c){
  if(c.typ==2)
    evs.insert(ev(1,bsf+1,c.loc+c.val));
  else
    bsf=max(bsf,c.val);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  in x,w;
  forn(z,n){
    cin>>x>>w;
    evs.insert(ev(2,2*w,x-w));
  }
  fors(i,evs)
    proc(*i);
  cout<<bsf<<endl;
  return 0;
}
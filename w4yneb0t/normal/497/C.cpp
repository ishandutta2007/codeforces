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
struct evt{
  in typ,r,id; //0 part, 1 actor
  evt(in a=0, in b=0, in c=0){
    typ=a;
    r=b;
    id=c;
  }
  bool operator<(const evt cp)const{
    if(r!=cp.r)
      return r<cp.r;
    return typ<cp.typ;
  }
};
vector<evt> evts;
VI lact,kact,lpart;
set<pair<in,in> > apts;
VI sol;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n;
  lpart=sol=VI(n);
  in tp;
  forn(i,n){
    cin>>lpart[i]>>tp;
    evts.PB(evt(0,tp,i));
  }
  cin>>m;
  lact=kact=VI(m);
  forn(i,m){
    cin>>lact[i]>>tp>>kact[i];
    evts.PB(evt(1,tp,i));
  }
  sort(all(evts));
  evt tt;
  set<pair<in,in> >::iterator it;
  forv(i,evts){
    tt=evts[i];
    if(tt.typ==0)
      apts.insert(MP(lpart[tt.id],tt.id));
    else{
      while(1){
	if(kact[tt.id]==0)
	  break;
	it=apts.lower_bound(MP(lact[tt.id],-1));
	if(it==apts.end())
	  break;
	--kact[tt.id];
	sol[it->second]=tt.id+1;
	apts.erase(it);
      }
    }
  }
  if(!apts.empty()){
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  forv(i,sol)
    cout<<sol[i]<<" ";
  cout<<"\n";
  return 0;
}
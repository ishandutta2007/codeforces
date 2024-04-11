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
  in typ;//0 isl, 1 bridg
  in l,r,id;
  evt(in a=0, in b=0, in c=0, in d=0){
    typ=a;
    l=b;
    r=c;
    id=d;
  }
  bool operator<(const evt cp)const{
    if(l!=cp.l)
      return l<cp.l;
    return typ<cp.typ;
  }
};
vector<evt> evts;
set<pair<in,in> > act;
VI ans;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  in pva=-1;
  in pvb=-1;
  in ca,cb;
  forn(i,n){
    cin>>ca>>cb;
    if(i)
      evts.PB(evt(0,ca-pvb,cb-pva,i-1));
    pva=ca;
    pvb=cb;
  }
  forn(i,m){
    cin>>ca;
    evts.PB(evt(1,ca,-1,i+1));
  }
  sort(all(evts));
  ans.resize(n-1);
  evt tp;
  forv(i,evts){
    tp=evts[i];
    if(tp.typ==0){
      act.insert(MP(tp.r,tp.id));
      continue;
    }
    if(act.empty())
      continue;
    if(act.begin()->first<tp.l){
      cout<<"No"<<endl;
      return 0;
    }
    ans[act.begin()->second]=tp.id;
    act.erase(act.begin());
  }
  if(!act.empty()){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  forv(i,ans)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}
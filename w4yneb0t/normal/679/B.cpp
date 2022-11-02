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
pair<in,in> btr(const pair<in,in>& t1, const pair<in,in>& t2){
  if(t1.first!=t2.first){
    if(t1.first>t2.first)
      return t1;
    return t2;
  }
  if(t1.second>t2.second)
    return t1;
  return t2;
}
VI cbs;
vector<vector<pair<in,in> > > mct;
const in mx=100009;
pair<in,in> ct(in m, in typ){
  assert(m>=0);
  if(typ==0 && m>=mx){
    in tid=upper_bound(all(cbs),m)-cbs.begin();
    --tid;
    assert(tid>=0 && tid<sz(cbs));
    pair<in,in> tp=ct(m-cbs[tid],0);
    ++tp.first;
    tp.second+=cbs[tid];
    return btr(tp,ct(tid,1));
  }
  pair<in,in>& tp=mct[typ][m];
  if(tp.first!=-1)
    return tp;
  if((m==0 && typ==0) || (m<=1 && typ==1)){
    tp.first=0;
    tp.second=0;
    return tp;
  }
  if(typ==1){
    if(cbs[m]<mx-5)
      return tp=ct(cbs[m]-1,0);
    tp=ct(cbs[m]-1-cbs[m-1],0);
    ++tp.first;
    tp.second+=cbs[m-1];
    return tp=btr(ct(m-1,1),tp);
  }
  in tid=upper_bound(all(cbs),m)-cbs.begin();
  --tid;
  assert(tid>=0 && tid<sz(cbs));
  tp=ct(m-cbs[tid],0);
  ++tp.first;
  tp.second+=cbs[tid];
  return tp=btr(tp,ct(tid,1));
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>m;
  cbs.resize(mx);
  mct.resize(2,vector<pair<in,in> >(mx,MP(-1,-1)));
  forv(i,cbs)
    cbs[i]=i*i*i;
  pair<in,in> tp=ct(m,0);
  cout<<tp.first<<" "<<tp.second<<endl;
  return 0;
}
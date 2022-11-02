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
void rt(VI v){
  cout<<sz(v)<<endl;
  forv(i,v)
    cout<<v[i]<<" ";
  cout<<endl;
  exit(0);
}
in n;
set<in> hv,gdx,gdy;
in x,y,l;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>l>>x>>y;
  in tp;
  forn(i,n){
    cin>>tp;
    hv.insert(tp);
    if(tp-x>=0)
      gdx.insert(tp-x);
    if(tp+x<=l)
      gdx.insert(tp+x);
    if(tp-y>=0)
      gdy.insert(tp-y);
    if(tp+y<=l)
      gdy.insert(tp+y);
  }
  in hvx=0;
  in hvy=0;
  in hvdb=-1;
  fors(i,gdx){
    if(hv.count(*i))
      hvx=1;
    if(gdy.count(*i))
      hvdb=*i;
  }
  fors(i,gdy){
    if(hv.count(*i))
      hvy=1;
  }
  if(hvx && hvy)
    rt({});
  if(hvx)
    rt({*gdy.begin()});
  if(hvy)
    rt({*gdx.begin()});
  if(hvdb!=-1)
    rt({hvdb});
  rt({*gdx.begin(),*gdy.begin()});
  return 0;
}
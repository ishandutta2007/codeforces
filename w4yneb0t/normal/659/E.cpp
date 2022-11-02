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
VI deg;
VVI egs;
queue<in> q;
in res=0;
set<pair<in,in> > egv;
pair<in,in> SP(const in& a, const in& b){
  if(a<b)
    return MP(a,b);
  return MP(b,a);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  deg.resize(n);
  egs.resize(n);
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
    ++deg[ta];
    ++deg[tb];
    egv.insert(SP(ta,tb));
  }
  forn(i,n){
    if(deg[i]==0){
      ++res;
    }
    if(deg[i]==1)
      q.push(i);
  }
  in tt;
  while(!q.empty()){
    ta=q.front();
    q.pop();
    if(deg[ta]==0){
      deg[ta]=-1;
      ++res;
      continue;
    }
    assert(deg[ta]==1);
    forv(i,egs[ta]){
      tt=egs[ta][i];
      if(egv.find(SP(tt,ta))!=egv.end()){
	egv.erase(SP(tt,ta));
	--deg[tt];
	if(deg[tt]==1)
	  q.push(tt);
      }
    }
  }
  cout<<res<<endl;
  return 0;
}
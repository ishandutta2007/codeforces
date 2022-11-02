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
VVI egs,egw;
VI plc1,plc2,id1,id2;
in n,m,l,s,t;
const in inf=1e10;
in mds(in pr, bool opt=0){
  in ap;
  forv(i,plc1){
    ap=min(inf,pr);
    egw[plc1[i]][id1[i]]=egw[plc2[i]][id2[i]]=ap+1;
    pr-=ap;
  }
  if(opt){
    forv(i,egs){
      forv(j,egs[i]){
	if(egs[i][j]<i)
	  continue;
	cout<<i<<" "<<egs[i][j]<<" "<<egw[i][j]<<endl;
      }
    }
  }
  VI dst(n,inf);
  dst[s]=0;
  priority_queue<pair<in,in>,vector<pair<in,in> >, greater<pair<in,in> > > q;
  q.push(MP(0,s));
  in u,d;
  while(!q.empty()){
    tie(d,u)=q.top();
    q.pop();
    if(dst[u]!=d)
      continue;
    forv(i,egs[u]){
      if(dst[egs[u][i]]>dst[u]+egw[u][i]){
	dst[egs[u][i]]=dst[u]+egw[u][i];
	q.push(MP(dst[egs[u][i]],egs[u][i]));
      }
    }
  }
  return dst[t];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>l>>s>>t;
  egs.resize(n);
  egw.resize(n);
  in ta,tb;
  in w;
  forn(zz,m){
    cin>>ta>>tb>>w;
    if(w){
      egs[ta].PB(tb);
      egs[tb].PB(ta);
      egw[ta].PB(w);
      egw[tb].PB(w);
      continue;
    }
    plc1.PB(ta);
    id1.PB(sz(egs[ta]));
    plc2.PB(tb);
    id2.PB(sz(egs[tb]));
    egs[ta].PB(tb);
    egs[tb].PB(ta);
    egw[ta].PB(w);
    egw[tb].PB(w);
  }
  in mn=0;
  in mx=sz(plc1)*inf+1;
  if(mds(mn)>l || mds(mx)<l){
    cout<<"NO"<<endl;
    return 0;
  }
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(mds(md)<=l)
      mn=md;
    else
      mx=md;
  }
  cout<<"YES"<<endl;
  assert(mds(mn,1)==l);
  return 0;
}
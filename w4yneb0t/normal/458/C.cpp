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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in cvot=0;
in ndd;
in best=1000000000000000LL;
in mx=100009;
in spt=0;
map<in,in>::iterator bopt;
in cb;
vector<vector<in> > cts;
map<in,in> av;
map<in,in> m;
void adc(in a){
  spt-=a;
  av[a]++;
  cvot--;
  if(bopt==av.end() || bopt->first>a){
    assert(bopt!=av.begin());
    spt+=a;
    cb--;
    if(cb==-1){
      bopt--;
      cb=bopt->second-1;
    }
    spt-=bopt->first;
  }
}
void mvstf(){
  while(cvot<ndd && bopt!=av.end()){
    cvot++;
    spt+=bopt->first;
    cb++;
    if(cb==bopt->second){
      bopt++;
      cb=0;
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in tn;
  cin>>tn;
  in ta,tb;
  cts.resize(mx);
  forn(i,tn){
    cin>>ta>>tb;
    if(tb==0)
      ta=0;
    cvot++;
    if(ta==0){
      continue;
    }
    spt+=tb;
    cts[ta].PB(tb);
  }
  forn(i,mx){
    sort(all(cts[i]));
    reverse(all(cts[i]));
    if(sz(cts[i])>0)
      m[i]=sz(cts[i]);
  }
  bopt=av.begin();
  cb=0;
  if(spt<best)
    best=spt;
  forn(i,mx){
    typeof(m.begin()) it,it2;
    it=m.begin();
    while(1){
      if(it==m.end())
	break;
      adc(cts[it->first][i]);
      if(it->second==1){
	it2=it;
	++it;
	m.erase(it2);
      }
      else{
	it->second--;
	++it;
      }
    }
    ndd=i+2;
    mvstf();
    if(cvot>=ndd && spt<best)
      best=spt;
  }
  cout<<best<<endl;
  return 0;
}
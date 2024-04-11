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
in m,k,p;
VVI egs;
VI nds;
VI usd;
void dfs(in u, in d, in pr){
  nds[d]++;
  forv(i,egs[u])
    if(egs[u][i]!=pr)dfs(egs[u][i],d+1,u);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>m>>k>>p;
  egs.resize(m);
  in ta,tb;
  forn(i,m-1){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  nds.resize(m+3,0);
  usd=nds;
  dfs(0,0,0);
  in ttc=0;
  in bst=0;
  in ttd=0;
  in ntg=0;
  for(in nxt=1;nxt<=m+1;nxt++){
    ttc+=ttd;
    usd[nxt]=nds[nxt];
    ttd+=nds[nxt];
    while(ttc>p){
      while(usd[ntg]==0)ntg++;
      usd[ntg]--;
      ttd--;
      ttc-=(nxt-ntg);
    }
    if(ttd>bst)bst=ttd;
  }
  if(bst>k)
    bst=k;
  cout<<bst<<endl;
  return 0;
}
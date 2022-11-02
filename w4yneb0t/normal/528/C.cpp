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
vector<map<in,in> > egs;
VI sx,sy;
void dfs(in u, in pr){
  if(pr!=-1){
    egs[u][pr]--;
    if(egs[u][pr]==0)
      egs[u].erase(pr);
  }
  in tp;
  while(sz(egs[u])!=0){
    tp=egs[u].begin()->first;
    egs[u][tp]--;
    if(egs[u][tp]==0)
      egs[u].erase(tp);
    dfs(tp,u);
  }
  if(pr!=-1){
    sx.PB(pr);
    sy.PB(u);
    if(sz(sx)%2)
      swap(sx.back(),sy.back());
  }
}

VI deg;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>n>>m;
  deg.resize(n,0);
  egs.resize(n);
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta][tb]++;
    egs[tb][ta]++;
    deg[ta]++;
    deg[tb]++;
  }
  in lst=-1;
  forn(i,n){
    if(deg[i]%2){
      if(lst==-1)
	lst=i;
      else{
	m++;
	ta=i;
	tb=lst;
	lst=-1;
	egs[ta][tb]++;
	egs[tb][ta]++;
      }
    }
  }
  assert(lst==-1);
  if(m%2){
    ta=tb=0;
    egs[ta][tb]++;
    egs[tb][ta]++;
    m++;
  }
  cout<<m<<"\n";
  dfs(0,-1);
  for(in i=sz(sx)-1;i>=0;i--){
    cout<<sx[i]+1<<" "<<sy[i]+1<<"\n";
  }
  return 0;
}
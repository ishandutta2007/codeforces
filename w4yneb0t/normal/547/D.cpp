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
string sol;
in n;
vector<map<in,in> > egs,egind;
in sd=0;
VI vst;
struct eulertour{
  void ini(in pn){
    n=pn;
    egs.clear();
    egs.resize(n);
  }
  void dfs(in u, in pr){
    vst[u]=1;
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
      tp=egind[pr][u];
      if(tp!=-1){
	sol[tp]='r';
	if(sd)
	  sol[tp]='b';
	sd=!sd;
      }
    }
  }
  void maketour(){
    forv(i,egs){
      if(vst[i]||sz(egs[i])==0)continue;
      dfs(i,-1);
    }
  }
};
eulertour tp;
in mx=200009;
VI degx,degy;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  sol.resize(n);
  egs.resize(2*mx+5);
  egind.resize(2*mx+5);
  vst=VI(2*mx+5,0);
  degx=degy=VI(mx,0);
  in ta,tb;
  forn(i,n){
    cin>>ta>>tb;
    degx[ta]++;
    degy[tb]++;
    egs[ta][tb+mx]++;
    egind[ta][tb+mx]=i;
    egs[tb+mx][ta]++;
    egind[tb+mx][ta]=i;
  }
  forn(i,mx){
    if(degx[i]%2){
      degx[i]++;
      degy[0]++;
      egs[i][mx]++;
      egind[i][mx]=-1;
      egs[mx][i]++;
      egind[mx][i]=-1;
    }
    if(degy[i]%2){
      degx[0]++;
      degy[i]++;
      egs[0][mx+i]++;
      egind[0][mx+i]=-1;
      egs[mx+i][0]++;
      egind[mx+i][0]=-1;
    }
  }
  if(degx[0]%2){
    degx[0]++;
    degy[0]++;
    egs[0][mx]++;
    egind[0][mx]=-1;
    egs[mx][0]++;
    egind[mx][0]=-1;
  }
  tp.maketour();
  cout<<sol<<"\n";
  return 0;
}
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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
in n;
vector<in> ft,fd;
vector<in> ntc;
vector<vector<in> > egs;
vector<in> ops;
vector<bool> ckd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  egs.resize(n,vector<in>(0));
  ft.resize(n,0);
  fd.resize(n,0);
  ntc.resize(n);
  ckd.resize(n,0);
  in ta,tb;
  forn(i,n-1){
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(i,n)
    cin>>ntc[i];
  forn(i,n){
    cin>>ta;
    ntc[i]^=ta;
  }
  queue<in> q;
  q.push(0);
  ckd[0]=1;
  in u,v;
  while(!q.empty()){
    u=q.front();
    q.pop();
    if(ntc[u]!=ft[u]){
      ops.PB(u+1);
      ft[u]^=1;
    }
    forv(i,egs[u]){
      v=egs[u][i];
      if(ckd[v])
	continue;
      ft[v]^=fd[u];
      fd[v]^=ft[u];
      ckd[v]=1;
      q.push(v);
    }
  }
  cout<<sz(ops)<<"\n";
  forv(i,ops)
    cout<<ops[i]<<"\n";
  return 0;
}
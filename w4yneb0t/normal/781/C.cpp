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
VI ord;
VVI egs;
VI vis;
void gen(in u, in pr){
  vis[u]=1;
  ord.PB(u);
  forv(i,egs[u]){
    if(egs[u][i]==pr)
      continue;
    if(vis[egs[u][i]])
      continue;
    gen(egs[u][i],u);
    ord.PB(u);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,k;
  cin>>n>>m>>k;
  egs.resize(n);
  vis.resize(n);
  in ta,tb;
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  gen(0,0);
  in nxt=0;
  in mxv=(2*n+k-1)/k;
  forn(z,k){
    in lft=sz(ord)-nxt;
    in cv=min(mxv,lft);
    if(cv==0){
      cout<<"1 1\n";
      continue;
    }
    cout<<cv<<" ";
    forn(zz,cv){
      cout<<ord[nxt++]+1<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
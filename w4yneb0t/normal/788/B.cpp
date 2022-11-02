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
queue<in> q;
VI vis;
VVI egs;
VI sdeg;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  scanf("%lld%lld",&n,&m);
  sdeg.resize(n);
  vis.resize(n);
  egs.resize(n);
  in ta,tb;
  in u;
  in s1=0;
  forn(z,m){
    scanf("%lld%lld",&ta,&tb);
    --ta;
    --tb;
    if(ta==tb)
      ++s1;
    else{
      ++sdeg[ta];
      ++sdeg[tb];
    }
    u=ta;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  q.push(u);
  vis[u]=1;
  while(!q.empty()){
    u=q.front();
    q.pop();
    forv(i,egs[u]){
      if(!vis[egs[u][i]]){
	q.push(egs[u][i]);
	vis[egs[u][i]]=1;
      }
    }
  }
  forn(i,n){
    if(!vis[i] && sz(egs[i])>0){
      printf("%lld\n",0LL);
      return 0;
    }
  }
  in sm=s1*(m-s1)+s1*(s1-1)/2;
  forn(i,n)
    sm+=sdeg[i]*(sdeg[i]-1)/2;
  printf("%lld\n",sm);
  return 0;
}
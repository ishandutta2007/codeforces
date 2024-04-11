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
void no(){
  cout<<"NO"<<endl;
  exit(0);
}
VVI egs;
VI x,y;
VVI d={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(in u, in pr, in pd, in mx, in my, in dpt){
  x[u]=mx;
  y[u]=my;
  if(sz(egs[u])>4)
    no();
  in nxt=0;
  forv(i,egs[u]){
    if(egs[u][i]==pr)
      continue;
    if(nxt==pd)
      ++nxt;
    dfs(egs[u][i],u,(nxt+2)%4,mx+(1LL<<dpt)*d[nxt][0],my+(1LL<<dpt)*d[nxt][1],dpt-1);
    ++nxt;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  x=y=VI(n);
  egs.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  dfs(0,0,-1,0,0,31);
  cout<<"YES"<<endl;
  forn(i,n)
    cout<<x[i]<<" "<<y[i]<<endl;
  return 0;
}
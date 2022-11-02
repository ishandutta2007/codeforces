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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,m,s,e;
vector<in> a,b;
const in mx=320;
const in lg=100009;
vector<in> eed[2];
in sw=0;
in nw=0;
in abest=0;
vector<vector<in> > nora;
in nor(in l, in tm){
  in tg=nora[l][tm];
  if(tg==n)
    return n;
  if(tg+1<eed[nw][l+1]){
    for(in i=eed[nw][l+1]-1;i>=tg+1;i--){
      nora[l+1][a[i]]=i;
    }
  }
  return tg;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m>>s>>e;
  nora.resize(mx,vector<in>(lg,n));
  a.resize(n);
  b.resize(m);
  forn(i,n)
    cin>>a[i];
  forn(i,m)
    cin>>b[i];
  forn(i,2)
    eed[i].resize(mx,n);
  for(in i=n-1;i>=0;i--){
    nora[0][a[i]]=i;
  }
  eed[0][0]=0;
  in nxt;
  forn(i,m){
    sw=i%2;
    nw=!sw;
    forn(j,mx)
      eed[nw][j]=eed[sw][j];
    for(in j=mx-2;j>=0;j--){
      if(eed[sw][j]>=n)
	continue;
      nxt=nor(j,b[i])+1;
      if(nxt>n)
	continue;
      if(eed[nw][j+1]>=nxt){
	eed[nw][j+1]=nxt;
	if((j+1)*e+i+1+nxt<=s && abest<j+1)
	  abest=j+1;
      }
    }
  }
  cout<<abest<<endl;
  return 0;
}
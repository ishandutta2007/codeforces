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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in inf=10000;
VVI isc;
VI md;
in n,m;
queue<in> q;
in cmd(){
  md=VI(n,inf);
  md[0]=0;
  q.push(0);
  in u;
  while(!q.empty()){
    u=q.front();
    q.pop();
    forn(i,n){
      if(isc[u][i]){
	if(md[i]>md[u]+1){
	  md[i]=md[u]+1;
	  q.push(i);
	}
      }
    }
  }
  return md[n-1];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  isc.resize(n,VI(n,0));
  in ta,tb;
  forn(i,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    isc[ta][tb]=isc[tb][ta]=1;
  }
  in cc=cmd();
  forn(i,n){
    forn(j,n)
      isc[i][j]=!isc[i][j];
  }
  cc=max(cmd(),cc);
  if(cc==inf)
    cout<<-1;
  else
    cout<<cc;
  cout<<endl;
  return 0;
}
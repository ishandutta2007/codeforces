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
VVI egs;
VI deg;
vector<string> v;
void imp(){
  cout<<"Impossible\n";
  exit(0);
}
queue<in> q;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  v.resize(n);
  forn(i,n)
    cin>>v[i];
  egs.resize(26);
  deg.resize(26);
  forn(i,n-1){
    forv(j,v[i]){
      if(j>=sz(v[i+1]))
	imp();
      if(v[i][j]!=v[i+1][j]){
	egs[v[i][j]-'a'].PB(v[i+1][j]-'a');
	++deg[v[i+1][j]-'a'];
	break;
      }
    }
  }
  forv(i,deg){
    if(deg[i]==0){
      q.push(i);
    }
  }
  string rs;
  while(!q.empty()){
    in u=q.front();
    q.pop();
    rs+=(u+'a');
    in tt;
    forv(i,egs[u]){
      tt=egs[u][i];
      --deg[tt];
      if(!deg[tt])
	q.push(tt);
    }
  }
  if(sz(rs)!=26)
    imp();
  cout<<rs<<endl;
  return 0;
}
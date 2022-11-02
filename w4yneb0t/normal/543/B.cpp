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
in n,m;
VVI egs;
VI vs;
void mkds(in s, vector<int>& d){
  vs=VI(n,0);
  d=vector<int>(n,1000000);
  d[s]=0;
  queue<in> q;
  q.push(s);
  vs[s]=1;
  while(!q.empty()){
    in u=q.front();
    q.pop();
    forv(i,egs[u]){
      if(vs[egs[u][i]])continue;
      d[egs[u][i]]=d[u]+1;
      vs[egs[u][i]]=1;
      q.push(egs[u][i]);
    }
  }
}
vector<vector<int> > d;
in s[2];
in t[2];
in l[2];
in td(in id, in x, in y){
  return d[s[id]][x]+d[x][y]+d[y][t[id]];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  egs.resize(n);
  d.resize(n);
  forn(i,m){
    in ta,tb;
    cin>>ta>>tb;
    ta--;
    tb--;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(i,2){
    cin>>s[i]>>t[i]>>l[i];
    s[i]--;
    t[i]--;
  }
  forn(i,n)
    mkds(i,d[i]);
  int bst=d[s[0]][t[0]]+d[s[1]][t[1]];
  forn(i,2){
    if(d[s[i]][t[i]]>l[i]){
      cout<<-1<<endl;
      return 0;
    }
  }
  forn(z,2){
    forn(x,n){
      forn(y,n){
	if(td(0,x,y)>l[0] || td(1,x,y)>l[1])continue;
	bst=min(bst,d[s[0]][x]+d[s[1]][x]+d[x][y]+d[y][t[0]]+d[y][t[1]]);
      }
    }
    swap(s[0],t[0]);
  }
  cout<<m-bst<<endl;
  return 0;
}
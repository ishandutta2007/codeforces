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
set<char> ts[3];
VVI mn;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(char c='a';c<='z';++c)
    ts[0].insert(c);
  for(char c='0';c<='9';++c)
    ts[1].insert(c);
  ts[2].insert('#');
  ts[2].insert('*');
  ts[2].insert('&');
  in n,m;
  cin>>n>>m;
  mn.resize(n,VI(3,1e10));
  string tp;
  forn(z,n){
    cin>>tp;
    forv(j,tp){
      forn(s,3){
	if(ts[s].count(tp[j])){
	  mn[z][s]=min(mn[z][s],min(j,m-j));
	}
      }
    }
  }
  in bst=1e10;
  forn(a,n){
    forn(b,n){
      if(a==b)
	continue;
      forn(c,n){
	if(a==c || b==c)
	  continue;
	bst=min(bst,mn[a][0]+mn[b][1]+mn[c][2]);
      }
    }
  }
  cout<<bst<<endl;
  return 0;
}
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
set<in> unseen;
const in mx=2e6+9;
char ans[mx];
in mxl=0;
string t;
char tt[mx];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  forn(i,mx)
    ans[i]='a';
  forn(i,mx)
    unseen.insert(i);
  in n;
  scanf("%d",&n);
  in k,x;
  set<in>::iterator it,it2;
  forn(z,n){
    scanf("%s",tt);
    t=string(tt);
    scanf("%d",&k);
    forn(zz,k){
      scanf("%d",&x);
      --x;
      mxl=max(mxl,x+sz(t));
      it=unseen.lower_bound(x);
      while(it!=unseen.end() && *it<x+sz(t)){
	it2=it;
	++it;
	ans[*it2]=t[*it2-x];
	unseen.erase(it2);
      }
    }
  }
  ans[mxl]='\0';
  printf("%s\n",ans);
  return 0;
}
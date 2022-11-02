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
const in mx=1000009;
in bst=0;
in n;
VI hs;
VI lst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  hs=VI(mx,0);
  lst=VI(mx,0);
  in a;
  forn(i,n){
    cin>>a;
    hs[a]=1;
  }
  in cl=0;
  forn(i,mx){
    lst[i]=cl;
    if(hs[i])
      cl=i;
  }
  forn(cb,mx){
    if(!hs[cb])continue;
    for(in mp=cb;mp<mx;mp+=cb){
      if(lst[min(mx-1,mp+cb)]>=mp)
	bst=max(bst,lst[min(mx-1,mp+cb)]-mp);
    }
  }
  cout<<bst<<endl;
  return 0;
}
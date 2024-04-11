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
in hp[2];
in att[2];
in df[2];
in cst[3];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  forn(i,2)
    cin>>hp[i]>>att[i]>>df[i];
  forn(i,3)
    cin>>cst[i];
  in bst=1000000000000LL;
  for(in nuat=att[0];nuat<=203;nuat++){
    if(nuat<=df[1])continue;
    for(in nudf=df[0];nudf<=101;nudf++){
      in chy=hp[0];
      in chm=hp[1];
      while(chm>0){
	chm-=nuat-df[1];
	chy-=max(0LL,att[1]-nudf);
      }
      in hpnd=max(0LL,1-chy);
      bst=min(bst,(nuat-att[0])*cst[1]+(nudf-df[0])*cst[2]+hpnd*cst[0]);
    }
  }
  cout<<bst<<endl;
  return 0;
}
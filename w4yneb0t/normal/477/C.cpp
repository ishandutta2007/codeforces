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
const in inf=1000000000LL;
string s,p;
VI bst;
VVI lrm;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>s>>p;
  bst.resize(sz(s)+1,0);
  lrm.resize(sz(s)+1,VI(sz(s)+1,inf));
  lrm[0][0]=0;
  forv(i,s){
    forv(j,lrm[i])
      lrm[i+1][j]=lrm[i][j];
    in cp=sz(p)-1;
    in cl=i;
    while(cp>=0 && cl>=0){
      if(p[cp]==s[cl])
	--cp;
      --cl;
    }
    ++cl;
    if(cp!=-1)continue;
    forv(j,s){
      lrm[i+1][j+1]=min(lrm[i+1][j+1],lrm[cl][j]+(i-cl+1)-sz(p));
    }
  }
  forv(i,lrm[sz(s)]){
    for(in j=lrm[sz(s)][i];j<=sz(s)-i*sz(p);++j)
      bst[j]=i;
  }
  forv(i,bst)
    cout<<bst[i]<<" ";
  cout<<endl;
  return 0;
}
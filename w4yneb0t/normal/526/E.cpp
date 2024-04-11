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
VI vals;
in n,qq,b;
vector<int> cgt;
vector<int> vist;
in bst;
in nom(in a){
  if(a<=0)return a+n;
  return a;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>qq;
  vals.resize(n);
  forn(i,n)
    cin>>vals[i];
  cgt.resize(n);
  vist.resize(n);
  in wtg,sm;
  forn(zz,qq){
    cin>>b;
    wtg=0;
    sm=0;
    forn(i,n){
      vist[i]=0;
      while(vals[wtg]+sm<=b){
	sm+=vals[wtg];
	++wtg;
	if(wtg==n)wtg=0;
	if(wtg==i)break;
      }
      cgt[i]=wtg;
      sm-=vals[i];
    }
    bst=n+10;
    in opt;
    in nupt;
    in stps;
    forn(i,n){
      opt=i;
      nupt=i;
      sm=0;
      stps=0;
      while(1){
	if(vist[nupt])break;
	vist[nupt]=1;
	sm+=nom(cgt[nupt]-nupt);
	nupt=cgt[nupt];
	++stps;
	while(sm>=n){
	  if(stps<bst)bst=stps;
	  sm-=nom(cgt[opt]-opt);
	  opt=cgt[opt];
	  --stps;
	}
      }
    }
    cout<<bst<<"\n";
  }
  return 0;
}
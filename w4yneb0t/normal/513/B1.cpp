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
in n;
in val(vector<in> pm){
  in r=0;
  forn(j,n+1){
    forn(i,j){
      in mn=n+10;
      for(in k=i;k<j;k++){
	if(pm[k]<mn)mn=pm[k];
      }
      r+=mn;
    }
  }
  return r;
}
in bst=-1;
vector<vector<in> > vld;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  in m;
  cin>>n>>m;
  vector<in> a;
  a.resize(n);
  forn(i,n)
    a[i]=i+1;
  in sf=0;
  do{
    in cs=val(a);
    if(cs>bst){
      bst=cs;
      sf=0;
    }
    if(cs==bst)sf++;
    if(sf==m){
      forn(i,n)
	cout<<a[i]<<" ";
      cout<<endl;
      return 0;
    }
  }while(next_permutation(all(a)));
  return 0;
}
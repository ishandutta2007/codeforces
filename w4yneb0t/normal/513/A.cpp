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
in wr[55][55][2];
in k1,k2;
in isw(in n1, in n2, in ptg){
  if(wr[n1][n2][ptg]!=0)
    return wr[n1][n2][ptg];
  if(ptg==0){
    if(n1==0)
      return wr[n1][n2][ptg]=-1;
    for(in i=1;i<=n1 && i<=k1;i++){
      if(isw(n1-i,n2,!ptg)==1)
	return wr[n1][n2][ptg]=1;
    }
    return wr[n1][n2][ptg]=-1;
  }
  if(n2==0)
    return wr[n1][n2][ptg]=1;
  for(in i=1;i<=n2 && i<=k2;i++){
    if(isw(n1,n2-i,!ptg)==-1)
      return wr[n1][n2][ptg]=-1;
  }
  return wr[n1][n2][ptg]=1;
}
in n1,n2;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n1>>n2>>k1>>k2;
  cout<<(isw(n1,n2,0)==1?"First":"Second")<<endl;
  return 0;
}
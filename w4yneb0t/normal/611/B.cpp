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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a,b;
  cin>>a>>b;
  in rs=0;
  for(in n1=1;n1<=62;++n1){
    for(in lc0=0;lc0<n1-1;++lc0){
      in cnb=(1LL<<n1)-1;
      cnb^=(1LL<<lc0);
      if(cnb>=a && cnb<=b)
	++rs;
    }
  }
  cout<<rs<<endl;
  return 0;
}
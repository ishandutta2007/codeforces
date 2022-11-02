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
in n,k;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  in cr=1;
  in df=k;
  cout<<cr<<" ";
  in dr=1;
  while(df>0){
    cr+=df*dr;
    dr*=-1;
    df--;
    cout<<cr<<" ";
  }
  for(in i=k+2;i<=n;i++){
    cout<<i<<" ";
  }
  cout<<"\n";
  return 0;
}
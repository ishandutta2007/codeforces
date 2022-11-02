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
  in h,tph,a,b;
  cin>>h>>tph>>a>>b;
  h=tph-h;
  in ct=14;
  while(h>0){
    if(ct>100 && a<=b){
      cout<<-1<<endl;
      return 0;
    }
    if(ct%24>=10 && ct%24<22)
      h-=a;
    else
      h+=b;
    ++ct;
  }
  cout<<(ct/24)<<endl;
  return 0;
}
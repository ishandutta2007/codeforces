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
string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  cin>>s;
  in sm=0;
  forv(i,s){
    if(i!=sz(s)-1 && s[i+1]!=s[i])
      sm+=(sz(s)-1-i)*(m-1);
    if(i!=0 && s[i-1]!=s[i])
      sm+=i*(m-1);
  }
  sm+=n*(m-1);
  in llod=-1;
  in llev=-2;
  forn(i,n){
    if(i>=2 && s[i-2]!=s[i]){
      if(i%2)
	llod=i-2;
      else
	llev=i-2;
    }
    if(!i)
      continue;
    if(s[i]==s[i-1])
      continue;
    sm-=i-1-max(llod,llev);
  }
  cout<<sm<<endl;
  return 0;
}
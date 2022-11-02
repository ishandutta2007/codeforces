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
  in s,x;
  cin>>s>>x;
  VI w={1,0};
  VI nw={0,0};
  in cx,cs;
  for(in i=0;i<50;++i){
    nw={0,0};
    cx=!!(x&1LL<<i);
    cs=!!(s&1LL<<i);
    forn(fd,2){
      forn(sd,2){
	forn(cc,2){
	  if((fd^sd)!=cx)
	    continue;
	  if((fd+sd+cc)%2!=cs)
	    continue;
	  nw[(fd+sd+cc)/2]+=w[cc];
	}
      }
    }
    w=nw;
  }
  if(s==x)
    w[0]-=2;
  cout<<w[0]<<endl;
  return 0;
}
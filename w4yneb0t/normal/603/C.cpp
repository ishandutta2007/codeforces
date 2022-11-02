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
const in mx=10;
VI grund;
in n,k;
in compgrund(in a){
  if(a<mx)
    return grund[a];
  if(a%2==1)
    return 0;
  if(k)
    return (compgrund(a/2)==1?2:1);
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  k%=2;
  in a;
  grund.resize(mx);
  grund[0]=0;
  for(in i=1;i<mx;++i){
    VI cc(5,0);
    cc[grund[i-1]]=1;
    if(i%2==0){
      if(k)
	cc[grund[i/2]]=1;
      else
	cc[0]=1;
    }
    forv(j,cc){
      if(!cc[j]){
	grund[i]=j;
	break;
      }
    }
  }
  in cgr=0;
  forn(i,n){
    cin>>a;
    cgr^=compgrund(a);
  }
  cout<<(cgr?"Kevin":"Nicky")<<endl;
  return 0;
}
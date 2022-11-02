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
in dc(in a){
  in r=0;
  while(a){
    r+=a%2;
    a/=2;
  }
  return r;
}
void qr(){
  in l,r;
  cin>>l>>r;
  in bsc=dc(r);
  in bsnb=r;
  forn(s,61){
    if(!(r&1LL<<s))continue;
    in c=r^1LL<<s;
    forn(i,s)
      c|=1LL<<i;
    in f;
    if(c>=l){
      f=dc(c);
      if(f>bsc || (f==bsc && c<bsnb)){
	bsc=f;
	bsnb=c;
      }
    }
  }
  cout<<bsnb<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  forn(z,n)
    qr();
  return 0;
}
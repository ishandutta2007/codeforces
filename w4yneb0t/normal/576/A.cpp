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
  in n;
  cin>>n;
  VI q;
  for(in i=2;i<=n;++i){
    bool isp=1;
    for(in j=2;j<i;++j){
      if(i%j==0)
	isp=0;
    }
    if(isp){
      for(in j=i;j<=n;j*=i)
	q.PB(j);
    }
  }
  cout<<sz(q)<<endl;
  forv(i,q)
    cout<<q[i]<<" ";
  cout<<endl;
  return 0;
}
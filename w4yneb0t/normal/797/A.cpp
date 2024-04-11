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
  in n,k;
  cin>>n>>k;
  VI x;
  for(in i=2;i<=n && k>0;++i){
    if(n%i)
      continue;
    x.PB(i);
    n/=i;
    --i;
    --k;
  }
  if(k!=0){
    cout<<-1<<endl;
    return 0;
  }
  x.back()*=n;
  forv(i,x)
    cout<<x[i]<<" ";
  cout<<endl;
  return 0;
}
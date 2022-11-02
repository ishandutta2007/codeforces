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
VI dvs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  for(in i=1;i*i<=n;++i){
    if(n%i)
      continue;
    dvs.PB(i);
    if(i*i!=n)
      dvs.PB(n/i);
  }
  sort(all(dvs));
  --k;
  if(sz(dvs)<=k)
    cout<<-1<<endl;
  else
    cout<<dvs[k]<<endl;
  return 0;
}
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
VI cnt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  cnt.resize(n);
  forn(i,n)
    cin>>cnt[i];
  in sm=0;
  for(in i=1;i<n;++i){
    if(cnt[i]+cnt[i-1]<k){
      sm+=k-cnt[i]-cnt[i-1];
      cnt[i]=k-cnt[i-1];
    }
  }
  cout<<sm<<endl;
  forv(i,cnt)
    cout<<cnt[i]<<" ";
  cout<<endl;
  return 0;
}
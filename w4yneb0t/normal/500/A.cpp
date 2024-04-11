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
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  in n,t;
  cin>>n>>t;
  in c=1;
  in a;
  for(in i=1;i<=n-1;i++){
    cin>>a;
    if(c==t){
      cout<<"YES"<<endl;
      return 0;
    }
    if(c==i)
      c+=a;
  }
  assert(c==n);
  if(c==t)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
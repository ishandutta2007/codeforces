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
VI belt;
VI hr;
map<in,in> hvs;
in n,a,b;
void fl(){
  cout<<"NO\n";
  exit(0);
}
void st(in i, in c){
  if(belt[i]==!c)
    fl();
  if(belt[i]==c)
    return;
  belt[i]=c;
  in u=hr[i];
  if(hvs.count(a-u))
    st(hvs[a-u],c);
  else{
    if(c==0)
      fl();
  }
  if(hvs.count(b-u))
    st(hvs[b-u],c);
  else{
    if(c==1)
      fl();
  }
}
void exa(in i){
  in u=hr[i];
  if(!hvs.count(a-u))
    st(i,1);
  if(!hvs.count(b-u))
    st(i,0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>a>>b;
  belt.resize(n,-1);
  in p;
  hr.resize(n);
  forn(i,n){
    cin>>p;
    hvs[p]=i;
    hr[i]=p;
  }
  forn(i,n){
    if(belt[i]==-1)
      exa(i);
  }
  cout<<"YES\n";
  forv(i,belt)
    cout<<!!belt[i]<<" ";
  cout<<"\n";
  return 0;
}
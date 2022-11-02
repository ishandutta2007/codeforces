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
in B;
const in inf=(1LL<<60LL);
in mul(in a, in b){
  if(b>=inf/a)
    return inf;
  return b*a;
}
in ad(in a, in b){
  if(a+b>=inf)
    return inf;
  return a+b;
}
in conv(string s){
  in t=0;
  for(in i=sz(s)-1;i>=0;--i){
    t*=10;
    t+=(s[i]-'0');
  }
  return t;
}
VI bs,nb;
string s;
VI pn;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>B;
  cin>>s;
  reverse(all(s));
  in n=sz(s);
  pn.resize(n+1);
  pn[0]=1;
  for(in i=1;i<=n;++i){
    pn[i]=mul(pn[i-1],B);
  }
  bs.resize(n+1,-1);
  nb.resize(n+1);
  bs[0]=0;
  nb[0]=0;
  in t;
  in nub,nun;
  for(in i=0;i<n;++i){
    if(bs[i]==-1)
      continue;
    for(in j=1;j<=10 && i+j<=n;++j){
      if(s[i+j-1]=='0' && j!=1)
	continue;
      t=conv(s.substr(i,j));
      if(t>=B)
	break;
      nub=bs[i]+1;
      nun=ad(mul(pn[bs[i]],t),nb[i]);
      if(bs[i+j]==-1 || bs[i+j]>nub || (bs[i+j]==nub && nb[i+j]>nun)){
	bs[i+j]=nub;
	nb[i+j]=nun;
      }
    }
  }
  assert(bs[n]!=-1);
  cout<<nb[n]<<endl;
  return 0;
}
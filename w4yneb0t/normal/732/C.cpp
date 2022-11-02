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
in f(in b, in d, in s){
  in cb=(b==0?0:((b-1)*3+1));
  in cd=(d==0?0:((d-1)*3+2));
  in cs=(s==0?0:((s-1)*3+3));
  return max(cb,max(cd,cs));
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in b,d,s;
  cin>>b>>d>>s;
  in mn=4e18;
  mn=min(mn,f(b,d,s));
  mn=min(mn,f(d,s,b));
  mn=min(mn,f(s,b,d));
  cout<<(mn-b-d-s)<<endl;
  return 0;
}
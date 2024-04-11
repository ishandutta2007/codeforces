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
in val(char c){
  in tc1=('@'<c);
  in tc2=('['>c);
  in tc3=('`'<c);
  in tc4=('{'>c);
  in cind=(c-'a');
  if(c>='A' && c<='Z')
    cind=(c-'A');
  tc1=tc1&&tc2;
  tc3=tc3&&tc4;
  ++cind;
  return (tc1*cind)-(tc3*cind);
}
string s;
in res=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  forv(i,s)
    res+=val(s[i]);
  cout<<res<<endl;
  return 0;
}
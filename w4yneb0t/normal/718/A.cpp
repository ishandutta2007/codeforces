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
string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,t;
  cin>>n>>t>>s;
  in pt=0;
  while(s[pt]!='.')
    ++pt;
  in cn=pt+1;
  while(cn<n && s[cn]<'5')
    ++cn;
  if(cn==n){
    cout<<s<<endl;
    return 0;
  }
  bool ed=0;
  while(t){
    --t;
    if(cn<=pt)
      break;
    if(s[cn]<'5')
      break;
    --cn;
    if(cn==pt)
      --cn;
    ++s[cn];
    s.resize(cn+1);
    while(s[cn]==char('9'+1)){
      s[cn]='0';
      --cn;
      if(cn<0){
	ed=1;
	break;
      }
      else{
	++s[cn];
	s.resize(max(cn+1,pt));
      }
    }
  }
  if(ed)
    cout<<"1";
  cout<<s<<endl;
  return 0;
}
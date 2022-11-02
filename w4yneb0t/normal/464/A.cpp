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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n,p;
string s;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>p;
  cin>>s;
  for(in i=n-1;i>=0;i--){
    string t=s;
    bool ok=1;
    while(1){
      t[i]++;
      if(t[i]-'a'>=p){
	ok=0;
	break;
      }
      if((i==0 || t[i]!=t[i-1])&&(i<=1 || t[i]!=t[i-2]))
	break;
    }
    for(in j=i+1;j<n;j++){
      t[j]='a'-1;
      while(1){
	t[j]++;
	if(t[j]-'a'>=p){
	  ok=0;
	  break;
	}
	if((j==0 || t[j]!=t[j-1])&&(j<=1 || t[j]!=t[j-2]))
	  break;
      }
    }
    if(ok){
      cout<<t<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
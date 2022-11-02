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
in n;
vector<int> pm;
const in lg=1000009;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  pm.resize(lg,1);
  pm[0]=pm[1]=0;
  forv(i,pm){
    if(pm[i]){
      for(in j=2*i;j<lg;j+=i)
	pm[j]=0;
    }
  }
  pm[0]=pm[1]=1;
  forn(i,n+1){
    if((!pm[i]) && (!pm[n-i])){
      cout<<i<<" "<<n-i<<endl;
      return 0;
    }
  }
  return 0;
}
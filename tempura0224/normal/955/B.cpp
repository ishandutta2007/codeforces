#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
const int mod=1e9+7;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  string s;
  cin>>s;
  map<char,int> mp;
  rep(i,s.size())
    mp[s[i]]++;
  int n=mp.size();
  if(n>4||n==1){
    cout<<"No"<<endl;
    return 0;
    }
  
  bool ok=true;
  if(n==3){
    ok=false;
    for(auto x:mp){
      if(x.second>1)ok=true;
      }
    }
  if(n==2){
    ok=true;
    for(auto x:mp){
      if(x.second==1)ok=false;
      }
    }
  if(ok)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
  }
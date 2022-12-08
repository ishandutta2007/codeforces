#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(ll)(n);i++)
typedef pair<int,long long> pint;
typedef long long ll;
const ll mod= 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  string s;
  cin>>s;
  int n=s.size();
  int cnt=0;
  rep(i,s.size()){
    if(s[i]=='o'){
      cnt++;
      n--;
      }
    }
  if(cnt==0){
    cout<<"YES"<<endl;
    return 0;
    }
  if(n%cnt==0){
    cout<<"YES"<<endl;
    }
  else cout<<"NO"<<endl;
  return 0;
  }
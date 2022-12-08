#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 510101010;
const int mod=1e9+7;
const ll longinf=1LL<<60;


int main() {
  int n;cin>>n;
  int ans=0;
  rep(i,n){
    int a;cin>>a;
    ans+=abs(a);
    }
  cout<<ans<<endl;
  return 0;
  }
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
  ll n,m;
  cin>>n>>m;
  while(1){
    if(m==0||n==0)break;
    if(n>=2*m)n%=(2*m);
    if(n!=0&&m>=2*n)m%=(2*n);
    if(m<2*n&&n<2*m)break;
    }
  cout<<n<<" "<<m<<endl;
  return 0;
  }
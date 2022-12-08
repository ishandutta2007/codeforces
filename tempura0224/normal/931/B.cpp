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

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  if(a<b) swap(a,b);
  int cnt=1;
  while((a+1)/2!=(b+1)/2){
    a=(a+1)/2;
    b=(b+1)/2;
    n/=2;
    cnt++;
    }
  if(n==2)cout<<"Final!"<<endl;
  else cout<<cnt<<endl;
  return 0;
  }
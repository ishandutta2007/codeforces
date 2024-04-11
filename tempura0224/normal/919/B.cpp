#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef pair<long long,long long> pll;
typedef long long ll;
const int inf   = 1<<30-1;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int calc(int n){
  int m=0;
  while(n>=1){
    m+=(n%10);
    n/=10;
    }
  return m;
  }

int main(){
  vector<int> v;
  rep(i,2e7){
    if(calc(i)==10){
      v.push_back(i);
      }
    }
  int k;
  cin>>k;
  cout<<v[k-1]<<endl;
  return 0;
  }
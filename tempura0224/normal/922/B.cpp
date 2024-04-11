#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<29;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n;
  cin>>n;
  int cnt=0;
  rep(i,n)rep(j,n){
    if(i<=j)continue;
    int k=(i+1)^(j+1);
    if(k>i+1&&k>j+1&&i+j+2>k&&k<=n)cnt++;
    }
  cout<<cnt<<endl;
  return 0;
  }
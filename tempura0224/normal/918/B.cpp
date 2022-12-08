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
const int inf   = 1<<29;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int m,n;
  cin>>m>>n;
  string a[2][m];
  string b[2][n];
  rep(i,m)cin>>a[0][i]>>a[1][i];
  rep(i,n)cin>>b[0][i]>>b[1][i];
  rep(i,n)rep(j,m){
    if(a[1][j]+';'==b[1][i]){
      cout<<b[0][i]<<" "<<b[1][i]<<" #"<<a[0][j]<<endl;
      continue;
      }
    }
  return 0;
  }
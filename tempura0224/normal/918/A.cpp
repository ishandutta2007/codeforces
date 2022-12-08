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
  int n;
  cin>>n;
  int f[1002];
  f[0]=f[1]=1;
  rep(i,1000)
    f[i+2]=f[i+1]+f[i];
  bool ok[n];
  rep(i,n)
  ok[i]=false;
  rep(i,1000){
    if(f[i]>n)break;
    ok[f[i]-1]=true;
    }
  rep(i,n){
    if(ok[i])cout<<"O";
    else
      cout<<"o";
    }
  cout<<endl;
  return 0;
  }
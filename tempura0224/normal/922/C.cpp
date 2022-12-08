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
  ll n,m;
  cin>>n>>m;
  n++;
  if(m>=10000){cout<<"No"<<endl;return 0;}
  rep(i,m){
    if(n%(i+1)!=0){cout<<"No"<<endl;return 0;}
    }
  cout<<"Yes"<<endl;
  return 0;
  }
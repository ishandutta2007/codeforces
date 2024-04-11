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
  int n,m;
  cin>>n>>m;
  if(m==1&&n>=1){cout<<"No"<<endl;return 0;}
  if(n+1<m||m==0){
    cout<<"No"<<endl;
    return 0;
    }
  if((n-m)%2==0)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
  }
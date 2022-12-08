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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;
const ll mod= 1e9+7;
const int inf=1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n,m;
  cin>>n>>m;
  if(n==m){cout<<"="<<endl;return 0;};
  if(n==1){cout<<"<"<<endl;return 0;}
  if(m==1){cout<<">"<<endl;return 0;}
  if(n==2){
    if(m==3){
      cout<<"<"<<endl;
      return 0;
      }
    if(m==4){
      cout<<"="<<endl;
      return 0;
      }
    }
  if(m==2){
    if(n==3){
      cout<<">"<<endl;
      return 0;
      }
    if(n==4){
      cout<<"="<<endl;
      return 0;
      }
    }
  if(n<m)cout<<">"<<endl;
  else cout<<"<"<<endl; 
  return 0;
  }
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
  int t;
  cin>>t;
  rep(j,t){
    int n;
    cin>>n;
    int l[n],r[n];
    rep(i,n)cin>>l[i]>>r[i];
    int now=0;
    rep(i,n){
      if(now>r[i]){
        cout<<"0 ";
        continue;
        }
      now=max(now,l[i]);
      cout<<now<<" ";
      now++;
      }
    cout<<endl;
    }
  return 0;    
  }
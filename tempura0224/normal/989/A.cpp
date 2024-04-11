#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
#include<string>
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
  string s;
  cin>>s;
  int n=s.size();
  rep(i,n-2){
    string t=s.substr(i,3);
    sort(t.begin(),t.end());
    if(t=="ABC"){
      cout<<"Yes"<<endl;
      return 0;
      }
    }
  cout<<"No"<<endl;
  return 0;
  }
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
  int n;cin>>n;
  map<string,int> mp;
  mp["purple"]=1;
  mp["green"]=2;
  mp["blue"]=3;
  mp["orange"]=4;
  mp["red"]=5;
  mp["yellow"]=6;
  string ans[]={"Power","Time","Space","Soul","Reality","Mind"};
  rep(i,n){
    string s;
    cin>>s;
    mp[s]=0;
    }
  cout<<(int)mp.size() -n<<endl;
  for(auto e:mp){
    if(e.second)cout<<ans[e.second-1]<<endl;
    }
  
  return 0;
  }
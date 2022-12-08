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
  int n,p;
  cin>>n>>p;
  string s;
  cin>>s;
  bool flag=false;
  rep(i,n-p){
    if(s[i]!=s[i+p]||s[i]=='.')
      flag=true;
    }
  if(flag){
    rep(i,n-p){
      if(s[i]=='.'){
        if(s[i+p]=='1')s[i]='0';
        if(s[i+p]=='0')s[i]='1';
        if(s[i+p]=='.'){
          s[i]='0';
          s[i+p]='1';
        }
      }
      }
    rep(i,n-p){
      if(s[i+p]=='.'){
        if(s[i]=='1')s[i+p]='0';
        if(s[i]=='0')s[i+p]='1';
        if(s[i]=='.')s[i+p]='0';
        }
      }
    rep(i,n)if(s[i]=='.')s[i]='0';
    cout<<s<<endl;
    }
  else cout<<"No"<<endl;
    
  return 0;
  }
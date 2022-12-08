#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
  int h,w;
  cin>>h>>w;
  string s[h];
  rep(i,h)cin>>s[i];
  rep(i,h-1)rep(j,w){
    if(s[i][j]=='S'&&s[i+1][j]=='W')
      {cout<<"No"<<endl;return 0;}
    if(s[i][j]=='W'&&s[i+1][j]=='S')
      {cout<<"No"<<endl;return 0;}
    }
  rep(i,h)rep(j,w-1){
    if(s[i][j]=='S'&&s[i][j+1]=='W')
      {cout<<"No"<<endl;return 0;}
    if(s[i][j]=='W'&&s[i][j+1]=='S')
      {cout<<"No"<<endl;return 0;}
    }
  cout<<"Yes"<<endl;
  rep(i,h)rep(j,w){
    if(s[i][j]=='.'){
      s[i][j]='D';
      }
    }
    rep(i,h)cout<<s[i]<<endl;
  return 0;
  }
#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<double,int> pint;
typedef long long ll;
const int inf   = 1<<29;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n;cin>>n;
  string s[n];
  pint p[n];
  rep(i,n){
    cin>>s[i];
    double cnts=0,cnth=0;
    rep(j,s[i].size()){
      if(s[i][j]=='s')cnts++;
      else cnth++;
      }
    if(cnth==0){cnth=1;cnts=inf;}
    p[i]=make_pair(cnts/cnth,i);
    }
  sort(p,p+n);
  reverse(p,p+n);
  string anss;
  rep(i,n)anss+=s[p[i].second];
  ll ans=0,cnt=0;
  rep(i,anss.size()){
    if(anss[i]=='s')cnt++;
    else ans+=cnt;
    }
  cout<<ans<<endl;
  return 0;
  
  }
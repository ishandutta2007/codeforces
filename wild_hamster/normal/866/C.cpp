#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define pb push_back
#define fst first
#define snd second
 
typedef long long ll;
typedef pair<int,int> pii;
 
const ll MOD=1e9+7;
 
int N,R;
int f[55],s[55];
double p[55];
double dp[55][5050];
 
void recalc(double x){
  for(int n=N-1;n>=0;n--){
    for(int r=R;r>=0;r--){
      dp[n][r]=p[n]*((double)f[n]+(r-f[n]>=0?dp[n+1][r-f[n]]:x))
	+(1.0-p[n])*((double)s[n]+(r-s[n]>=0?dp[n+1][r-s[n]]:x));
      if(n==0) return;
      dp[n][r]=min(dp[n][r],x);
    }
  }
}
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>N>>R;
  double x=0.0;
  for(int i=0;i<N;i++){
    cin>>f[i]>>s[i];
    x+=f[i];
    int pr;cin>>pr;
    p[i]=(double)pr/100.0;
  }
 
 
  memset(dp,0,sizeof dp);
  // cout<<dp[N][0]<<'\n';
 
  double l=x,r=1e10;
  for (int i = 0; i < 100; i++){
    x=(l+r)/2;
    recalc(x);
    if(dp[0][R]<x){
      r=x;
    }else{
      l=x;
    }
  }
 
  cout<<fixed<<setprecision(10);
  cout<<x<<'\n';
 
  return 0;
}
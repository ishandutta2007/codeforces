#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  if(n==2){
    cout << a[0] SP a[1] << endl;
    return 0;
  }
  sort(all(a));
  vector<vector<pair<int,pair<int,int>>>> dp(n,vector<pair<int,pair<int,int>>>(n));
  dp[1][0]={a[1]-a[0],{0,0}};
  for(int i=2;i<n;i++){
    for(int j=0;j<i-1;j++){
      dp[i][j]={max(dp[i-1][j].first,a[i]-a[i-1]),{i-1,j}};
    }
    dp[i][i-1]={IINF,{-1,-1}};
    for(int j=0;j<i-1;j++){
      int c=max(dp[i-1][j].first,a[i]-a[j]);
      if(c<dp[i][i-1].first){
        dp[i][i-1]={c,{i-1,j}};
      }
    }
  }
  int x=-1,mi=IINF;
  for(int i=0;i<n-1;i++){
    if(max(dp[n-1][i].first,a[n-1]-a[i])<mi){
      x=i;
      mi=max(dp[n-1][i].first,a[n-1]-a[i]);
    }
  }
  pair<int,int> now={n-1,x},zero={0,0};
  pair<int,int> next;
  stack<int> s;
  queue<int> q;
  bool iss=true;
  while(now!=zero){
    // cout << now.first SP now.second << endl;
    if(iss) s.push(a[now.first]);
    else q.push(a[now.first]);
    if(now.first-now.second==1) iss=!iss;
    now=dp[now.first][now.second].second;
  }
  cout << a[0] << " ";
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}
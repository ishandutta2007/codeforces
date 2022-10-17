#include <bits/stdc++.h>
using namespace std;

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
  vector<int> dp(n,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]==1) dp[i]=IINF;
  }
  vector<int> p(n),ch(n,0);
  p[0]=0;
  for(int i=1;i<n;i++){
    cin >> p[i];
    p[i]--;
    ch[p[i]]++;
  }
  queue<int> s;
  int k=0;
  for(int i=0;i<n;i++){
    if(ch[i]==0){
      s.push(i);
      dp[i]=1;
      k++;
    }
  }
  while(!s.empty()){
    int now=s.front();
    if(now==0) break;
    s.pop();
    if(a[p[now]]){
      dp[p[now]]=min(dp[p[now]],dp[now]);
    }else{
      dp[p[now]]+=dp[now];
    }
    ch[p[now]]--;
    if(ch[p[now]]==0) s.push(p[now]);
  }
  cout << k-dp[0]+1 << endl;
  return 0;
}
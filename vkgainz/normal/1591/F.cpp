#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 1e5 + 5;
 
int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(auto &a : A) cin >> a;
  vector<ll> dp(N+1);
  vector<ll> altSum(N+1);
  dp[0] = 1LL;
  altSum[0] = 1LL;
  ll MOD = 998244353;
  vector<int> lst(N+1);
  vector<int> stack;
  for(int i=1;i<=N;i++) {
    while(!stack.empty() && A[i-1] <= A[stack.back()-1])
      stack.pop_back();
    if(stack.empty())
      lst[i] = 0;
    else
      lst[i] = stack.back();
    stack.push_back(i);
  }
  for(int i=1;i<=N;i++) {
    int x = lst[i];
    ll a = altSum[i-1];
    if(x > 0 && (i-x)%2==0) a -= altSum[x-1];
    else if(x > 0) a+=altSum[x-1];
    dp[i] = A[i-1]*1LL*a;
    if(x > 0) {
      if((i-x)%2==0)
        dp[i] += dp[x];
      else
        dp[i] -= dp[x];
    }
    dp[i] %= MOD;
    if(dp[i] < 0) dp[i] += MOD;   
    altSum[i] = -altSum[i-1] + dp[i];
    altSum[i] %= MOD;
 
    if(altSum[i] < 0) altSum[i] += MOD;
  }
  cout << dp[N] << "\n";
}
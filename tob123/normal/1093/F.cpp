#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 1e5+10;
const int kmax = 105;
const ll MOD = 998244353;

ll N, K, L;
ll A[n], totSum[n];
ll sum[n][kmax];
deque<ll> dp[kmax];

void printAll(int x){
  cout << "tot: " << x << endl;
  for(int i=1; i<=K; i++){
    cout << i << "(" << sum[x][i] << "): ";
    for(ll a : dp[i]){
      cout << a << " ";
    }
    cout << endl;
  }
  cout << endl;
}

ll sumMod(ll a, ll b){
  return (a + b) % MOD;
}
ll subMod(ll a, ll b){
  return (MOD + a - b) % MOD;
}

int main(){
  cin >> N >> K >> L;
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  totSum[0] = 1;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=K; j++){
      if(A[i] == j || A[i] == -1){
        sum[i][j] = sum[i-1][j];
        dp[j].push_front(subMod(totSum[i-1], sum[i-1][j]));
        sum[i][j] = sumMod(sum[i][j], dp[j].front());
        if(dp[j].size() >= L){
          sum[i][j] = subMod(sum[i][j], dp[j].back());
          dp[j].pop_back();
        }
      }
      else{
        sum[i][j] = 0;
        dp[j].resize(0);
      }
      totSum[i] = sumMod(totSum[i], sum[i][j]);
    }
    //printAll(i);
  }

  cout << totSum[N] << endl;

  return 0;
}
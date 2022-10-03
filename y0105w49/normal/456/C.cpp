//begin 20:20

#include <iostream>

using namespace std;

const int N=100000;
long long c[N+1],dp[N+1];
int n;

int main() {

  cin >> n;

  int a;
  for (int i = 0; i<n; i++) {
    cin >> a;
    c[a]++;
  }

  dp[0]=0;
  dp[1]=c[1];
  long long q;
  for (int i = 2; i<=N; i++) {
    q = c[i]*i;
    q+=dp[i-2];
    dp[i]=q>dp[i-1]?q:dp[i-1];
  }

  cout << dp[N] << endl;

  return 0;

}

//done 20:35
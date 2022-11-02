#include<iostream>
#include<cstring>

using namespace std;

typedef long long Int;
const Int MO = 1000000007;

Int mul(Int a, Int b)
{
  return a * b % MO;
}

Int add(Int a, Int b)
{
  a += b;
  if(a >= MO) a -= MO;
  return a;
}

Int dp[2][128];
Int comb[128][128];
int n, a[10];

int main()
{
  comb[0][0] = 1;
  for(int i=1; i<128; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for(int j=1; j<i; ++j)
      comb[i][j] = add(comb[i-1][j], comb[i-1][j-1]);
  }
  
  cin >> n;
  for(int i=0; i<10; ++i)
    cin >> a[i];
  
  dp[0][0] = 1;
  for(int i=1; i<=10; ++i) {
    int d = i % 10;
    int p = i&1, q = 1-p;
    memset(dp[p], 0, sizeof(dp[p]));
    for(int k=n; k>=0; --k)
      for(int e=a[d]; k+e<=n; ++e)
        dp[p][k+e] = add(dp[p][k+e], mul(dp[q][k], comb[d ? k+e : (k+e-1)][e]));
  }
  
  Int res = 0;
  for(int i=1; i<=n; ++i)
    res = add(res, dp[0][i]);
  cout << res << endl;
  return 0;
}
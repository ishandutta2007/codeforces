#include<cstdio>

using namespace std;

typedef long long Int;

const int MOD = 1000000007;

int add(int a, int b)
{
  a += b;
  if(a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b)
{
  a -= b;
  if(a < 0) a += MOD;
  return a;
}

char S[1<<20];
int B[1<<20], W[1<<20], X[1<<20];

int func(int a, int b, char c) // [a, b]
{
  if(a > b) return 0;
  int *p = (c=='B' ? B : (c=='W' ? W : X));
  return p[b] - p[a-1];
}

int noBW[1<<20][2];
int onlyW[1<<20][2];
int onlyB[1<<20][2];
int noW[1<<20][2];
int pow2[1<<20];

int main()
{
  int n, k;
  scanf("%d%d%s", &n, &k, &S[1]);
  
  if(2*k > n) {
    puts("0");
    return 0;
  }
  
  for(int i=1; i<=n; ++i) {
    B[i] = B[i-1] + !!(S[i]=='B');
    W[i] = W[i-1] + !!(S[i]=='W');
    X[i] = X[i-1] + !!(S[i]=='X');
  }
  
  if(k == 1) {
    int res = 0;
    if(func(1, n, 'B') == 0) res++;
    if(func(1, n, 'W') == 0) res++;
    for(int i=1; i+1<=n; ++i)
      if(func(1, i, 'B') == 0 && func(i+1, n, 'W') == 0)
        res++;
    int tmp = 1;
    for(int i=1; i<=n; ++i)
      if(S[i] == 'X')
        tmp = add(tmp, tmp);
    printf("%d\n", sub(tmp, res));
    return 0;
  }
  
  noBW[0][0] = noBW[0][1] = 1;
  if(S[1] != 'W') noBW[1][0] = 1;
  if(S[1] != 'B') noBW[1][1] = 1;
  for(int i=2; i<=n; ++i) {
    if(S[i] != 'W') {
      noBW[i][0] = add(noBW[i][0], add(noBW[i-1][0], noBW[i-1][1]));
      if(i>=k && func(i-k+1, i-1, 'W') == 0)
        noBW[i][0] = sub(noBW[i][0], noBW[i-k][1]);
    }
    if(S[i] != 'B') {
      noBW[i][1] = add(noBW[i][1], add(noBW[i-1][0], noBW[i-1][1]));
      if(i>=k && func(i-k+1, i-1, 'B') == 0)
        noBW[i][1] = sub(noBW[i][1], noBW[i-k][0]);
    }
  }
  
  for(int i=1; i<=n; ++i) {
    if(S[i] != 'W') {
      onlyW[i][0] = add(onlyW[i][0], add(onlyW[i-1][0], onlyW[i-1][1]));
      if(i>=k && func(i-k+1, i-1, 'W') == 0)
        onlyW[i][0] = sub(onlyW[i][0], onlyW[i-k][1]);
      onlyB[i][0] = add(onlyB[i][0], add(onlyB[i-1][0], onlyB[i-1][1]));
      if(i>=k && func(i-k+1, i-1, 'W') == 0)
        onlyB[i][0] = add(onlyB[i][0], noBW[i-k][1]);
    }
    if(S[i] != 'B') {
      onlyB[i][1] = add(onlyB[i][1], add(onlyB[i-1][0], onlyB[i-1][1]));
      if(i>=k && func(i-k+1, i-1, 'B') == 0)
        onlyB[i][1] = sub(onlyB[i][1], onlyB[i-k][0]);
      onlyW[i][1] = add(onlyW[i][1], add(onlyW[i-1][0], onlyW[i-1][1]));
      if(i>=k && func(i-k+1, i-1, 'B') == 0)
        onlyW[i][1] = add(onlyW[i][1], noBW[i-k][0]);
    }
  }
  
  noW[n+1][0] = 1;
  for(int i=n; i>=1; --i) {
    if(S[i] != 'W') {
      noW[i][0] = add(noW[i][0], add(noW[i+1][0], noW[i+1][1]));
    }
    if(S[i] != 'B') {
      noW[i][1] = add(noW[i][1], add(noW[i+1][0], noW[i+1][1]));
      if(i+k<=n+1 && func(i, i+k-1, 'B') == 0)
        noW[i][1] = sub(noW[i][1], noW[i+k][0]);
    }
  }
  
  pow2[0] = 1;
  for(int i=1; i<=n; ++i)
    pow2[i] = add(pow2[i-1], pow2[i-1]);
  
  int res = 0;
  res = add(res, add(noBW[n][0], noBW[n][1]));
  res = add(res, add(onlyW[n][0], onlyW[n][1]));
  res = add(res, add(onlyB[n][0], onlyB[n][1]));

  for(int i=n-k+1; i>=1; --i)
    if(func(i, i+k-1, 'W') == 0)
      res = add(res, (Int)onlyW[i-1][1] * add(noW[i+k][0], noW[i+k][1]) % MOD);
  
  printf("%d\n", sub(pow2[func(1, n, 'X')], res));
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 505;

#define int long long

int n, m, x, y, z;

struct Mat {
  bool T[N][N];
  void init(void) {
    memset(T, 0, sizeof(T));
  }
  friend Mat operator * (Mat a, Mat b) {
    Mat now;
    now.init();
    bitset <N> A[N], B[N];
    for(int i = 1; i <= n; ++ i) A[i] = B[i] = 0;
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= n; ++ j) A[i][j] = a.T[i][j];
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= n; ++ j) B[i][j] = b.T[j][i];
    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= n; ++ j) {
	now.T[i][j] = !!((A[i] & B[j]).count());
      }
    }
    return now;
  }
  void print(void) {
    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= n; ++ j) putchar(T[i][j] + '0');
      puts("");
    }
  }
}A[65], B[65];

bool pd(Mat a) {
  int res = 0;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) res += a.T[i][j];
  }
  return !!res;
}

main(void) {
  cin >> n >> m;
  for(int i = 1; i <= m; ++ i) {
    scanf("%lld%lld%lld", &x, &y, &z);
    if(!z) A[0].T[x][y] = 1;
    else B[0].T[x][y] = 1;
  }
  for(int k = 1; k <= 64; ++ k) {
    A[k] = A[k - 1] * B[k - 1];
    B[k] = B[k - 1] * A[k - 1];
  }
  //A[0].print();
  //B[0].print();
  //cerr << A[0].T[1][2] <<" " << B[0].T[2][2] << endl;
  //puts("");
  //A[1].print();

  Mat now;
  now.init();
  now.T[1][1] = 1;

  if(pd(now * A[63])) {
    puts("-1");
    return 0;
  }

  bool cxt = 0;

  int ans = 0;
  
  for(int i = 62; i >= 0; -- i) {
    if(!cxt) {
      if(pd(now * A[i])) {
	now = now * A[i];
	cxt ^= 1;
	ans += (1LL << i);
      }
    }
    else {
      if(pd(now * B[i])) {
	now = now * B[i];
	cxt ^= 1;
	ans += (1LL << i);
      }
    }
  }
  if(ans > 1e18) puts("-1");
  else cout << ans << endl;
}
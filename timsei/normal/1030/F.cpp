#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

#define int long long

#define lowbit(x) (x & (-x))

typedef long long LL;
const int mod = 1e9 + 7;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
}

LL S[N], A[N], W[N];
int n, q;

void add(int x, LL v) {
  for(int i = x; i < N; i += lowbit(i))
    S[i] += v;
}

LL Sum(int x) {
  LL res = 0;
  for(int i = x; i; i -= lowbit(i))
    res += S[i];
  return res;
}

namespace BIT {
  int S[N];
  void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i))
      Add(S[i], v);
  }
  int Sum(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
      Add(res, S[i]);
    return res;
  }
}

LL calc(int l, int r, int x) {
  if(x < l || x > r) return 0LL;
  //cerr << l <<" " << r << " " << x << endl;
  //for(int i = A[x] - (x - l); i <= A[x] - (x - r); ++ i)
  //cerr << i <<" ";
  //puts("");
  LL ans = 0;
  Add(ans, 1LL * sub(A[x] - x) * ((Sum(x - 1) - Sum(l - 1)) % mod) % mod);
  Sub(ans, sub(BIT :: Sum(x - 1) - BIT :: Sum(l - 1)));
  //cerr << ans << endl;
  Add(ans, sub(BIT :: Sum(r) - BIT :: Sum(x)));
  //cerr << ans << endl;
  Sub(ans, 1LL * sub(A[x] - x) * ((Sum(r) - Sum(x)) % mod) % mod);
  //cerr << l <<" " << r <<" " << x <<" " << ans << endl;
  //cerr << BIT :: Sum(r) - BIT :: Sum(l - 1) << endl;
  return ans;
}

main() {
  cin >> n >> q;
  for(int i = 1; i <= n; ++ i)
    scanf("%lld", &A[i]);
  for(int i = 1; i <= n; ++ i)
    scanf("%lld", &W[i]),
      add(i, W[i]),
      BIT :: add(i, 1LL * W[i] * sub(A[i] - i) % mod);
  int x, y, l, r;
  for(; q --;) {
    scanf("%lld%lld", &x, &y);
    if(x < 0) {
      x = -x;
      add(x, -W[x]);
      BIT :: add(x, 1LL * W[x] * sub(x - A[x]) % mod);
      W[x] = y;
      add(x, W[x]);
      BIT :: add(x, 1LL * W[x] * sub(A[x] - x) % mod);
    }
    else {
      l = x, r = y;
      if(l == r) {
	puts("0");
	continue;
      }
      LL All = Sum(r) - Sum(l - 1);
      int L = l, R = r, res = R;
      while(L <= R) {
	int mid = (L + R) >> 1;
	if(Sum(mid) - Sum(l - 1) >= All / 2 + (All & 1)) {
	  res = mid;
	  R = mid - 1;
	}
	else L = mid + 1;
      }
      printf("%lld\n", calc(l, r, res));
    }
  }
}
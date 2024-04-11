#include <bits/stdc++.h>
using namespace std;

const int Q = 4500;

mt19937_64 rng(uint64_t(new char));

long long rand_int(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}

bool query(long long l, long long r) {
  cout << l << " " << r << endl;
  string res;
  cin >> res;
  if (l == r && res[0] == 'Y') {
    exit(0);
  }
  return res[0] == 'Y';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  long long n;
  cin >> n >> k;

  long long lo = 1;
  long long hi = n;

  for (int i = 0; i < Q; ++i) {
    if (hi - lo + 1 > 8 * k) {
      long long mid = (lo + hi) / 2;
      if (query(lo, mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    } else {
      long long ndx = rand_int(lo, hi);
      query(ndx, ndx);
    }

    lo = max(1LL, lo - k);
    hi = min(n, hi + k);
  }
  assert(0);
}
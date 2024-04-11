#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N], t[N];
int n, m, Zero, One, ans;

typedef pair <int, int> pii;
#define mp make_pair

const int m1 = 10007;
const int m2 = 998244353;

pii operator + (pii a, pii b) {
  return mp((a.first + b.first) % m1, (a.second + b.second) % m2);
}

pii operator - (pii a, pii b) {
  return mp((a.first - b.first % m1 + m1) % m1, (a.second - b.second % m2 + m2) % m2);
}

pii operator * (pii a, pii b) {
  return mp(1LL * a.first * b.first % m1, 1LL * a.second * b.second % m2);
}

pii B[N], S[N];

pii getHash(int l, int r) {
  if(l > r) throw;
  return S[r] - S[l - 1] * B[r - l + 1];
}

int solve(int x, int y) {
  //cerr << x <<" " << y << endl;
  pii L = mp(-1, -1), R = mp(-1, -1);
  int Sum = 0;
  for(int i = 1; i <= n; ++ i) {
    if(s[i] == '0') {
      if(L.first == -1) L = getHash(Sum + 1, Sum + x);
      else if(L != getHash(Sum + 1, Sum + x)) return 0;
      Sum += x;
    }
    else {
      if(R.first == -1) R = getHash(Sum + 1, Sum + y);
      else if(R != getHash(Sum + 1, Sum + y)) return 0;
      Sum += y;
    }
  }
  return L != R;
}

int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  B[0] = mp(1, 1); B[1] = mp(137, 137);
  for(int i = 2; i <= m; ++ i) B[i] = B[i - 1] * B[1];
  for(int i = 1; i <= max(n, m); ++ i)
    S[i] = S[i - 1] * B[1] + mp(t[i], t[i]);
  for(int i = 1; i <= n; ++ i) if(s[i] == '0') ++ Zero; else ++ One;
  for(int i = 1; i <= m / Zero; ++ i) {
    int other = m - i * Zero;
    if(other % One == 0 && other > 0)
      ans += solve(i, other / One);
  }
  cout << ans << endl;
}
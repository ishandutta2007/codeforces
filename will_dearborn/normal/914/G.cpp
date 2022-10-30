#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int mod = 1000000007;
const ll inv2 = (mod+1) / 2;

const int MAXN = (1 << 17);

void fft(vi &a, int low, int high)
{
  if(low == high - 1)
    return;
  int len = (high - low) / 2, mid = low + len;
  fft(a, low, mid);
  fft(a, mid, high);

  for(int i = low; i < mid; i++)
  {
    int x1 = a[i];
    int x2 = a[i + len];
    a[i] = (x1 - x2) % mod;
    a[i + len] = (x1 + x2) % mod;
  }
}

void inv_fft(vi &a, int low, int high)
{
  if(low == high - 1)
    return;
  int len = (high - low) / 2, mid = low + len;
  for(int i = low; i < mid; i++)
  {
    int y1 = a[i];
    int y2 = a[i + len];
    a[i] = (y1 + y2) * inv2 % mod;
    a[i + len] = (y2 - y1) * inv2 % mod;
  }
  inv_fft(a, low, mid);
  inv_fft(a, mid, high);
}

vi mul1(vi A, vi B) {
  fft(A, 0, A.size());
  fft(B, 0, B.size());
  vi res(A.size());
  for(int i = 0; i < res.size(); i++)
    res[i] = A[i] * (ll)B[i] % mod;
  inv_fft(res, 0, res.size());
  return res;
}

vi mul2(vi A, vi B) {
  vi res(A.size());
  for (int m = 0; m < res.size(); ++m) {
    ll sum = 0;
    for (int s=m; s; s=(s-1)&m) {
      sum += A[s] * (ll)B[m ^ s];
    }
    sum += A[0] * (ll)B[m];
    res[m] = sum % mod;
  }
  return res;
}

void conv(vi & x) {
  for (int b = 1; b < x.size(); b *= 2) {
    for (int s = 0; s < x.size(); s += 2 * b) for (int i = s; i < s + b; ++i) {
      x[i] = (x[i] + x[i^b]) % mod;
    }
  }
}

void convinv(vl & x) {
  for (int b = 1; b < x.size(); b *= 2) {
    for (int s = 0; s < x.size(); s += 2 * b) for (int i = s; i < s + b; ++i) {
      x[i] = (x[i] - x[i^b]) % mod;
    }
  }
}

vi f(vi a) {
  vi fib(a.size());
  fib[1] = 1;
  for (int i = 2; i < fib.size(); ++i) fib[i] = (fib[i-1] + fib[i-2]) % mod;
  for (int i = 0; i < a.size(); ++i) {
    a[i] = a[i] * (ll)fib[i] % mod;
  }
  conv(a);
  return a;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(MAXN);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++a[x];
  }
  vi b = mul1(a, a);
  vi c = mul2(a, a);
  a = f(a);
  b = f(b);
  c = f(c);
  vl res(a.size());
  for (int i = 0; i < a.size(); ++i) {
    res[i] = a[i] * (ll)b[i] % mod * c[i] % mod;
  }
  convinv(res);
  ll sum = 0;
  for (int b = 1; b < a.size(); b *= 2) {
    sum += res[b];
  }
  cout << (sum % mod + mod) % mod << endl;
  return 0;
}
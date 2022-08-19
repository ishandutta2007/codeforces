/**
 *    author:  tourist
 *    created: 10.11.2018 17:47:40       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long la, ra, ta, lb, rb, tb;
  cin >> la >> ra >> ta;
  cin >> lb >> rb >> tb;
  if (ra - la < rb - lb) {
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }
  long long g = __gcd(ta, tb);
  long long ans = 0;
  if (lb > la) {
    long long shift = (lb - la) / g;
    lb -= shift * g;
    rb -= shift * g;
  }
  if (lb < la) {
    long long shift = (la - lb) / g;
    lb += shift * g;
    rb += shift * g;
  }
  auto inter = [&](long long A, long long B, long long C, long long D) {
    long long L = max(A, C);
    long long R = min(B, D);
    long long res = max(R - L + 1, 0LL);
    return res;
  };
  for (long long delta = -42; delta <= 42; delta++) {
    ans = max(ans, inter(la, ra, lb + delta * g, rb + delta * g));
  }
  cout << ans << '\n';
  return 0;
}
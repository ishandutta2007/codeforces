#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll work(ll n) {
  if (n <= 2) return 1;
  return n - work(n + 1 >> 1);
}
int Query(ll x) {
  printf("? %lld\n", x); fflush(stdout);
  int opt; scanf("%d", &opt); return opt;
}
void Guess(ll n) {
  //printf("Guess n = %lld\n", n);
  if (n == 1) {
    printf("= %lld\n", n); fflush(stdout);
    return ;
  }
  /*
  if (n <= 10) {
    Query(1);
    for (int i = 1; i < n; i++) {
      int x = Query(1 + i);
      //printf("Guess %d\n", i + 1);
      if (x == 1) {
        printf("! %lld\n", i); fflush(stdout);
        return ;
      }
      Query(1);
    }
    printf("! %lld\n", n); fflush(stdout);
    return ;
  }
  */
  vector<ll> po;
  ll l = 1, r = n - 1, ans = n;
  while (l <= r) {
    ll mid = l + r >> 1;
    po.push_back(mid), l = mid + 1;
  }
  reverse(po.begin(), po.end());
  ll pos = n, flag = -1;
  for (auto v: po) pos += flag * v, flag *= -1;
  Query(pos);
  l = 1, r = n - 1, flag = (po.size() & 1) ? 1 : -1;
  while (l <= r) {
    ll mid = l + r >> 1;
    //printf("l = %lld, r = %lld, mid = %lld, pos = %lld\n", l, r, mid, pos);
    pos += mid * flag, flag *= -1;
    bool sta = Query(pos);
    if (sta == 1) r = mid - 1, ans = mid;
    else l = mid + 1; 
  }
  printf("= %lld\n", ans); fflush(stdout);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    ll n;
    scanf("%lld", &n);
    Guess(n);
  }
  return 0;
}

/*
1
14 12
*/
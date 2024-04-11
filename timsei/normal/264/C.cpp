%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

typedef long long LL;

int val[N], col[N], n, q, a, b;

struct NODE {
  LL col, ans;
  friend bool operator < (NODE a, NODE b) {
    return a.ans < b.ans;
  }
};

LL MAX[N];

NODE fir, sec;

vector < int > cxt;

LL calc(int x) {
  if(x < 0) return 0;
  else return MAX[x];
}

bool cmp(int x, int y) {
  return calc(x) > calc(y);
}

void upd(int x) {
  if(fir.col == x) {
    fir.ans = MAX[x];
    return;
  }
  else if(sec.col == x) {
    if(MAX[x] > fir.ans) {
      swap(fir, sec);
      fir.ans = MAX[x];
    }
    else {
      sec.ans = MAX[x];
    }
  }
  else {
    if(MAX[x] >= fir.ans) {
      sec = fir;
      fir = (NODE){x, MAX[x]};
    }
    else if(MAX[x] > sec.ans) {
      sec = (NODE){x, MAX[x]}; 
    }
  }
}

LL solve() {
  for(int i = 1; i <= 1e5; ++ i) MAX[i] = -1e18;
  fir.col = -1, fir.ans = 0;
  sec = fir;
  sec.col = -2;
  LL ans = 0;
  for(int i = 1; i <= n; ++ i) {
    LL Dp = -1e18;
    if(MAX[col[i]] != -1e18)
    Dp = max(Dp, MAX[col[i]] + 1LL * a * val[i]);
    if(fir.col != col[i])
      Dp = max(Dp, fir.ans + 1LL * b * val[i]);
    else Dp = max(Dp, sec.ans + 1LL * b * val[i]);
    MAX[col[i]] = max(MAX[col[i]], Dp);
    upd(col[i]);
    ans = max(ans, Dp);
  }
  return ans;
}

int main() {
  //n = 1e5; q = 500;
  cin >> n >> q;
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &val[i]);
  }
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &col[i]);
  }
  for(; q --;) {
    scanf("%d%d", &a, &b);
    //a = rand() % n, b = rand() % n;
    //solve();
    printf("%lld\n", solve());
  }
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

struct NODE {
  int x, y;
  friend bool operator < (NODE a, NODE b) {
	return a.x < b.x;
  }

  void input() {
	scanf("%lld%lld", &x, &y);
  }
}P[N];

int n, m, x, y, ans = 1e18;
int Lp[N], Rp[N], Ls[N], Rs[N];

int get(int x) {
  int l = 1, r = n, res = 0;
  while(l <= r) {
	int mid = (l + r) >> 1;
	if(P[mid].x <= x) {
	  res = mid; l = mid + 1;
	}
	else r = mid - 1;
  }
  return res;
}

bool pd(int x, int who, int l, int r) {
  if(P[x].x * P[x].x > who) return 0;
  int now = get((int)sqrt(who) + P[x].x);
  //cerr << P[x].x <<" " << P[now].x <<" " << x <<" " << now << " " << who <<  endl;
  // [x, now]
  if(x == 1 && now == n) return 1;
  now = min(now, r);
  int L = Lp[x - 1], R = Rp[x - 1];
  L = min(L, Ls[now + 1]);
  R = max(R, Rs[now + 1]);
  //cerr << x <<" " << who <<" " << l <<" " << r << " " << L <<" " << R << endl;
  if((R - L) * (R - L) > who) return 0;
  if(max(L * L, R * R) + (P[x].x * P[x].x) > who) return 0;
  return 1;
}

void solve(int x) {
  //cerr << x << " " << get(-P[x].x) << endl;
  int l = 0, r = 1e18, res = 1e18;
  while(l <= r) {
	int mid = (l + r) >> 1;
	//cerr << l <<" " << r <<" " << x << endl;
	if(pd(x, mid, x, get(-P[x].x))) {
	  r = mid - 1; res = mid;
	}
	else l = mid + 1;
  }
  //if(res == 1380575650441LL) cerr << x << endl;
  ans = min(ans, res);
}

void init() {
  Ls[n + 1] = Lp[0] = 1e9, Rs[n + 1] = Rp[0] = -1e9;
  for(int i = 1; i <= n; ++ i) Lp[i] = min(Lp[i - 1], P[i].y), Rp[i] = max(Rp[i - 1], P[i].y);
  for(int i = n; i >= 1; -- i) Ls[i] = min(Ls[i + 1], P[i].y), Rs[i] = max(Rs[i + 1], P[i].y);
  ans = min(ans, (Rs[1] - Ls[1]) * (Rp[n] - Lp[n]));
}

main() {
  scanf("%lld", &n);
  for(int i = 1; i <= n; ++ i) P[i].input();
  sort(P + 1, P + n + 1);
  init();
  for(int i = 1; i <= n; ++ i) 
	if(P[i].x <= 0) solve(i);
  //cerr << "HERE" << endl;
  for(int i = 1; i <= n; ++ i) P[i].x = - P[i].x;
  sort(P + 1, P + n + 1);
  init();
  for(int i = 1; i <= n; ++ i) if(P[i].x <= 0) solve(i);
  ans = min(ans, (P[n].x - P[1].x) * (P[n].x - P[1].x));
  cout << ans << endl;
}
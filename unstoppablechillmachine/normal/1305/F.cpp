#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

map<ll, int> used;
map<ll, int> cnt;
vector<int> pr;
int timer, T;

void fact(ll kek) {
  for (auto it : pr) {
    if (it * 1ll * it > kek) {
      break;
    }
    if (kek % it == 0) {
      kek /= it;
      if (used[it] < timer) {
        cnt[it]++;
        used[it] = timer;
      }
      while (kek % it == 0) {
        kek /= it;
      }
    }
  }
  if (kek > 1) {
    if (used[kek] < timer) {
      cnt[kek]++;
      used[kek] = timer;
    }
  }
}

const int S = 1e6 + 10;
bool p[S];
ll pref[S], suf[S];
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= 1e6; i++) {
    if (!p[i]) {
      pr.pb(i);
      if (i <= 1000) {
        for (int j = i * i; j <= 1e6; j += i) {
          p[j] = true;
        }
      }
    }
  }
	int n;
  cin >> n;
  vector<ll> a(n);
  int ch = 0;
  for (auto &it : a) {
    cin >> it;
    if (it % 2 == 0) {
      ch++;
    }
  }
  sort(all(a));
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i - 1];
  }
  vector<ll> delta;
  for (int i = 1; i < n; i++) {
    delta.pb(a[i] - a[i - 1]);
  }
  sort(all(delta));
  delta.resize(unique(all(delta)) - delta.begin());
  if (SZ(delta) == 1) {
    if (a[0] == 1) {
      cout << n << '\n';
      exit(0);
    }
    else {
      cout << 0 << '\n';
      exit(0);
    }
  }
  vector<int> take;
  vector<bool> was(n);
  T = min(100LL, SZ(delta));
  for (int i = 0; i < T; i++) {
    for (;;) {
      int pos = rnd() % SZ(delta);
      if (!was[pos]) {
        take.pb(delta[pos]);
        was[pos] = true;
        break;
      }
    }
    take.pb(delta[rnd() % SZ(delta)]);
  }
  for (auto it : take) {
    timer++;
    if (it > 2) {
      fact(it - 1);
    }
    if (it > 1) {
      fact(it);
    }
    fact(it + 1);
  }
  vector<ll> interesting;
  for (auto it : cnt) {
    if (it.S >= T / 4) {
      interesting.pb(it.F);
    }
  }
  int ans = n - ch;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] * 1ll * (i - 1) - pref[i - 1] + suf[i + 1] - a[i - 1] * 1ll * (n - i) < ans) {
      ans = a[i - 1] * 1ll * (i - 1) - pref[i - 1] + suf[i + 1] - a[i - 1] * 1ll * (n - i);
    }
  }
  for (int i = 0; i < 200; i++) {
    ll sum = 0;
    for (int j = 0; j < n; j++) {
      ll vl = a[j] % pr[i];
      if (a[j] == vl) {
        sum += pr[i] - vl;
      }
      else {
        sum += min(vl, pr[i] - vl);  
      }
      if (sum >= ans) {
        break;
      }
    }
    if (sum < ans) {
      ans = sum;
    }
  }
  for (int i = 0; i < min(SZ(interesting), 50LL); i++) {
    ll sum = 0;
    for (int j = 0; j < n; j++) {
      ll vl = a[j] % interesting[i];
      if (a[j] == vl) {
        sum += interesting[i] - vl;
      }
      else {
        sum += min(vl, interesting[i] - vl);  
      }
      if (sum >= ans) {
        break;
      }
    }
    if (sum < ans) {
      ans = sum;
    }
  }
  for (int i = max(50LL, SZ(interesting) - 50); i < SZ(interesting); i++) {
    ll sum = 0;
    for (int j = 0; j < n; j++) {
      ll vl = a[j] % interesting[i];
      if (a[j] == vl) {
        sum += interesting[i] - vl;
      }
      else {
        sum += min(vl, interesting[i] - vl);  
      }
      if (sum >= ans) {
        break;
      }
    }
    if (sum < ans) {
      ans = sum;
    } 
  }
  for (int i = 50; i < SZ(interesting) - 50LL; i++) {
    if (clock() * 1.0 / CLOCKS_PER_SEC > 2.4) {
      break;
    }
    ll sum = 0;
    for (int j = 0; j < n; j++) {
      ll vl = a[j] % interesting[i];
      if (a[j] == vl) {
        sum += interesting[i] - vl;
      }
      else {
        sum += min(vl, interesting[i] - vl);  
      }
      if (sum >= ans) {
        break;
      }
    }
    if (sum < ans) {
      ans = sum;
    } 
  }
  cout << ans << '\n';
}
#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;
 
ll inf = 1LL << 62;
 
int n;
ll a[200100], b[200100], t[200100];
pair<ll, int> e[400100];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> t[i];
    e[2 * i] = {a[i], i};
    e[2 * i + 1] = {b[i], i};
  }
  sort(e, e + 2 * n);
  ll lt = 0;
  multiset<ll> ts;
  int p = 0;
  ll r = 0;
  while (p < 2 * n) {
    if (!ts.empty()) {
      ll dt = e[p].first - lt, st = *ts.begin();
      r += dt / st;
      lt += (dt / st) * st;
    }
    int h = 0;
    ll nt = inf;
    while (p + h < 2 * n && min(nt, (ts.empty() ? inf : lt + *ts.begin())) > e[p + h].first) {
      int i = e[p + h].second;
      ll ht = e[p + h].first;
      if (a[i] == ht)
        nt = min(nt, a[i] + t[i]);
      else
        ts.erase(ts.find(t[i]));
      h++;
    }
    if (p + h >= 2 * n)
      break;
    r++;
    lt = min(nt, (ts.empty() ? inf : lt + *ts.begin()));
    for (int hh = 0; hh < h; hh++) {
      int i = e[p + hh].second;
      ll ht = e[p + hh].first;
      if (a[i] == ht)
        ts.insert(t[i]);
    }
    p += h;
  }
  cout << r << "\n";
}
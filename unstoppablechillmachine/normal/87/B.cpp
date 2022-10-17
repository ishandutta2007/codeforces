//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n;
  cin >> n;
  map<string, pii> kek;
  map<string, bool> err;
  kek["void"] = {0, 0};
  for (int i = 0; i < n; i++) {
    string type;
    cin >> type;
    if (type == "typedef") {
      string a, b;
      cin >> a >> b;
      int cnt1 = 0, cnt2 = 0;
      while (!a.empty() && a[0] == '&') {
        a.erase(a.begin());
        cnt1++;  
      }
      while (!a.empty() && a.back() == '*') {
        a.pop_back();
        cnt2++;
      }
      if (kek.find(a) == kek.end()) {
        kek[a] = {0, 0};
        err[a] = true;
      }
      int vc = min(cnt1, cnt2);
      cnt1 -= vc;
      cnt2 -= vc;
      if (err[a]) {
        kek[b] = {0, 0};
        err[b] = true;
        continue;
      }
      pii was = kek[a], cur;
      cur.F = was.F + cnt1;
      cur.S = was.S + cnt2;
      vc = min(cur.F, cur.S);
      cur.F -= vc;
      cur.S -= vc;
      if (cur.F > cur.S) {
        err[b] = true;
        continue;
      }
      kek[b] = cur;
      err[b] = false;
    }
    else {
      string a;
      cin >> a;
      int cnt1 = 0, cnt2 = 0;
      while (!a.empty() && a[0] == '&') {
        a.erase(a.begin());
        cnt1++;  
      }
      while (!a.empty() && a.back() == '*') {
        a.pop_back();
        cnt2++;
      }
      assert(!a.empty());
      if (kek.find(a) == kek.end()) {
        err[a] = true;
      }
      if (err[a]) {
        cout << "errtype\n";
        continue;
      }
      pii was = kek[a];
      was.F += cnt1;
      was.S += cnt2;
      int vc = min(was.F, was.S);
      was.F -= vc;
      was.S -= vc;
      if (was.F > was.S) {
        cout << "errtype\n";
        continue;
      }
      cout << "void";
      for (int p = 0; p < was.S; p++) {
        cout << '*';
      }
      cout << '\n';
    }
  }  
}
 
signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}
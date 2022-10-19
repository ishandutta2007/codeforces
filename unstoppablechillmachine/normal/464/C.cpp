//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define int ll
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

const int MOD = 1e9 + 7;

pair<int, string> parse(string s) {
  pair<int, string> res;
  res.F = s[0] - '0';
  for (int i = 3; i < SZ(s); i++) {
    res.S += s[i];
  }
  return res;
}

void source() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<pair<int, string> > query(q);
  for (int i = 0; i < q; i++) {
    string t;
    cin >> t;
    query[q - i - 1] = parse(t);
  }
  vector<int> val(10), lol(10);
  for (int i = 0; i < 10; i++) {
    val[i] = i;
    lol[i] = 10;
  }
  for (auto it : query) {
    int digit = it.F, nval = 0, nlol = 1;
    for (auto cc : it.S) {
      int cd = cc - '0';
      nlol = (nlol * lol[cd]) % MOD;
      nval = ((nval * lol[cd]) % MOD + val[cd]) % MOD;
    }
    val[digit] = nval;
    lol[digit] = nlol;
  }
  int ans = 0;
  for (auto it : s) {
    int digit = (it - '0');
    ans = ((ans * lol[digit]) % MOD + val[digit]) % MOD;
  }
  cout << ans;
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
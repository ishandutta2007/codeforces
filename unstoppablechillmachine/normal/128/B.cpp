//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
//#define int ll
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

string s;
int k;

void go(vector<int> &arr, int curlen) {
  if (curlen > 0) {
    if (k <= SZ(arr)) {
      for (int i = arr[0]; i < arr[0] + curlen; i++) {
        cout << s[i];
      }
      exit(0);
    }
    else {
      k -= SZ(arr);
    }
  }
  vector<vector<int>> have(26);
  for (auto it : arr) {
    if (s[it + curlen] >= 'a') {
      have[s[it + curlen] - 'a'].pb(it);
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!have[i].empty()) {
      go(have[i], curlen + 1);
    }
  }
}

void source() {
  cin >> s >> k;
  s += "#";
  vector<int> arr;
  for (int i = 0; i + 1 < SZ(s); i++) {
    arr.pb(i);
  }
  go(arr, 0);
  cout << "No such line.";
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
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
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  string s;
  int need;
  cin >> s >> need;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (auto it : s) {
    if (it >= 'a' && it <= 'z') {
      cnt0++;
    }  
    else if (it == '?') {
      cnt1++;
    }
    else {
      cnt2++;
    }
  }  
  if (cnt0 == need) {
    for (auto it : s) {
      if (it >= 'a' && it <= 'z') {
        cout << it;
      }
    }
  }
  else if (cnt0 < need) {
    if (cnt2 == 0) {
      cout << "Impossible";
    }
    else {
      bool was = false;
      for (int i = 0; i < SZ(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
          cout << s[i];
        }
        else if (s[i] == '*' && !was) {
          was = true;
          for (int j = 0; j < need - cnt0; j++) {
            cout << s[i - 1];
          }
        }
      }
    }
  }
  else {
    if (cnt0 - need > cnt1 + cnt2) {
      cout << "Impossible";
    }
    else {
      vector<char> ans;
      int kek = 0;
      for (int i = 0; i < SZ(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
          ans.pb(s[i]);
        }
        else if (cnt0 - need - kek > 0) {
          kek++;
          ans.pop_back();
        }
      }
      assert(SZ(ans) == need);
      for (auto it : ans) {
        cout << it;
      } 
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
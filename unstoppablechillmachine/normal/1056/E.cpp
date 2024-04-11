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

mt19937 Random(int(time(0)));

const ll P = 239017;

const int N = 1e6 + 10;
ll p_pow[N], hs[N];
int n, MOD;

vector<int> lol = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403, 1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447, 1000000453, 1000000459, 1000000483, 1000000513};


_ ll get_hash(int l, int r) {
  ll res = (l ? hs[r] - hs[l - 1] : hs[r]);
  return ((res + 2 * MOD) % MOD * p_pow[n - r]) % MOD;
}

bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void source() {
  MOD = lol[Random() % 30];
  string s, t;
  cin >> s >> t;
  int cnt0 = 0, cnt1 = 0;
  for (auto it : s) {
    if (it == '0') {
      cnt0++;
    }
    else {
      cnt1++;
    }
  } 
  hs[0] = t[0];
  p_pow[0] = 1;
  n = SZ(t) - 1;
  for (int i = 1; i < SZ(t); i++) {
    p_pow[i] = (p_pow[i - 1] * P) % MOD;
    hs[i] = (hs[i - 1] + t[i] * p_pow[i]) % MOD;
  }
  int ans = 0;
  for (int len = 1; len * cnt0 < SZ(t); len++) {
    if ((SZ(t) - len * cnt0) % cnt1) {
      continue;
    }
    int len2 = (SZ(t) - len * cnt0) / cnt1, cur = 0, a0 = 0, a1 = 0;
    ll ind0 = 0, ind1 = 0;
    bool t = true;
    for (auto it : s) {
      if (it == '0') {
        if (!a0++) {
          ind0 = get_hash(cur, cur + len - 1);
          cur += len;
          continue;
        }
        else {
          if (get_hash(cur, cur + len - 1) != ind0) {
            t = false;
            break;
          }
          cur += len;
        }
      }
      else {
        if (!a1++) {
          ind1 = get_hash(cur, cur + len2 - 1);
          cur += len2;
          continue;
        }
        else{
          if (get_hash(cur, cur + len2 - 1) != ind1) {
            t = false;
            break;
          }
          cur += len2;
        }
      }
    }
    if (t && ind0 != ind1) {
      ans++;
    }
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
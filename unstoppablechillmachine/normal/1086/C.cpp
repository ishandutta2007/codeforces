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
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void gg(vector<int> &to) {
  int n = SZ(to);
  vector<bool> used(n);
  vector<int> have;
  for (int i = 0; i < n; i++) {
    if (to[i] != -1) {
      assert(!used[to[i]]);
      used[to[i]] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      have.pb(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (to[i] == -1) {
      assert(!have.empty());
      to[i] = have.back();
      have.pop_back();
    }
  } 
  assert(have.empty());
}

void out(vector<int> &to) {
  gg(to);
  cout << "YES\n";
  vector<bool> used(SZ(to));
  for (auto it : to) {
    assert(!used[it]);
    used[it] = true;
    cout << char('a' + it);
  }
  cout << '\n';
}

bool can1(string s, string a, vector<int> to, int ind) {
  int k = SZ(to);
  vector<bool> used(k);
  for (int i = 0; i < k; i++) {
    if (to[i] != -1) {
      assert(!used[to[i]]);
      used[to[i]] = true;
    }
  }
  if (to[s[ind] - 'a'] == -1 && used[a[ind] - 'a']) {
    return false;
  }
  if (to[s[ind] - 'a'] != -1) {
    assert(to[s[ind] - 'a'] == a[ind] - 'a');
  }
  to[s[ind] - 'a'] = a[ind] - 'a';
  used[a[ind] - 'a'] = true;
  int n = SZ(s);
  for (int i = ind + 1; i < n; i++) {
    int curs = s[i] - 'a', cura = a[i] - 'a';
    if (to[curs] != -1) {
      if (to[curs] > cura) {
        out(to);
        return true;
      }
      if (to[curs] < cura) {
        return false;
      }
    }
    else {
      int cc = -1;
      for (int j = cura + 1; j < k; j++) {
        if (!used[j]) {
          cc = j;
          break;
        }
      }
      if (cc != -1) {
        to[curs] = cc;
        out(to);
        return true;
      }
      if (used[cura]) {
        return false;
      }
      to[curs] = cura;
      used[cura] = true;
    }
  }
  out(to);
  return true;
}

bool can2(string s, string b, vector<int> to, int ind) {
  int k = SZ(to);
  vector<bool> used(k);
  for (int i = 0; i < k; i++) {
    if (to[i] != -1) {
      assert(!used[to[i]]);
      used[to[i]] = true;
    }
  }
  if (to[s[ind] - 'a'] == -1 && used[b[ind] - 'a']) {
    return false;
  }
  if (to[s[ind] - 'a'] != -1) {
    assert(to[s[ind] - 'a'] == b[ind] - 'a');
  }
  to[s[ind] - 'a'] = b[ind] - 'a';
  used[b[ind] - 'a'] = true;
  int n = SZ(s);
  for (int i = ind + 1; i < n; i++) {
    int curs = s[i] - 'a', curb = b[i] - 'a';
    if (to[curs] != -1) {
      if (to[curs] < curb) {
        out(to);
        return true;
      }
      if (to[curs] > curb) {
        return false;
      }
    }
    else {
      int cc = -1;
      for (int j = curb - 1; j >= 0; j--) {
        if (!used[j]) {
          cc = j;
          break;
        }
      }
      if (cc != -1) {
        to[curs] = cc;
        out(to);
        return true;
      }
      if (used[curb]) {
        return false;
      }
      to[curs] = curb;
      used[curb] = true;
    }
  }
  out(to);
  return true;
}

void source() {
  int t;
  cin >> t;
  for (int test = 0; test < t; test++) {
    int k;
    string s, a, b;
    cin >> k >> s >> a >> b;
    if (a > b) {
      cout << "NO\n";
      continue;
    }
    int len = SZ(a);
    int ind = len;
    vector<int> to(k, -1);
    vector<bool> used(k);
    bool ok = true;
    for (int i = 0; i < len; i++) {
      if (a[i] != b[i]) {
        ind = i;
        break;
      }
      int curs = s[i] - 'a', cura = a[i] - 'a';
      if (to[curs] != -1) {
        if (to[curs] != cura) {
          ok = false;
          break;
        }
      }
      else {
        if (!used[cura]) {
          used[cura] = true;
          to[curs] = cura;
        }
        else {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    if (ind == len) {
      if (ok) {
        out(to);
      }
      else {
        cout << "NO\n";
      }
      continue;
    }
    int curs = s[ind] - 'a', cura = a[ind] - 'a', curb = b[ind] - 'a';
    if (to[curs] == -1) {
      int cc = -1;
      for (int i = cura + 1; i < curb; i++) {
        if (!used[i]) {
          cc = i;
          break;
        }
      }
      if (cc != -1) {
        to[curs] = cc;
        out(to);
      }
      else {
        if (!can1(s, a, to, ind)) {
          if (!can2(s, b, to, ind)) {
            cout << "NO\n";
          }
        }
      }
    }
    else {
      if (to[curs] < cura || to[curs] > curb) {
        cout << "NO\n";
      }
      if (to[curs] > cura && to[curs] < curb) {
        out(to);
      }
      if (to[curs] == cura) {
        if (!can1(s, a, to, ind)) {
          cout << "NO\n";
        }
      }
      if (to[curs] == curb) {
        if (!can2(s, b, to, ind)) {
          cout << "NO\n";
        }
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
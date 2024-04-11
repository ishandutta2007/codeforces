#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

vi f(vi v, int x) {
  int n = v.size();
  vi tmp;
  for (int i = 1; i <= x; ++i) tmp.push_back(v[n-i]);
  for (int i = 0; i < n - x; ++i) tmp.push_back(v[i]);
  return tmp;
}

void out(vi v) {
  for (auto x : v) cerr << x << ' '; cerr << endl;
}

vi solve(vi v) {
  int n = v.size();
  vi need(n), rneed(n);
  for (int i = 0; i < n; ++i) {
    need[i] = i;
    rneed[i] = n - 1 - i;
  }
  vi res;
  while (v != need) {
    //out(v);
    //assert(res.size() <= 3 * n + 2);
    assert(res.size() <= 6100);
    if (v == rneed) {
      res.push_back(n);
      v = f(v, res.back());
      continue;
    }
    bool ok = 0;
    for (int i = 2; i < n; ++i) {
      if (abs(v[0] - v[i]) == 1 && abs(v[i-1] - v[i]) != 1) {
        ok = 1;
        res.push_back(n - i);
        v = f(v, res.back());
        //cerr << i << " ok1\n";
        break;
      }
    }
    if (!ok) {
      for (int i = 1; i < n; ++i) {
        if (abs(v.back() - v[i]) == 1 && abs(v[i-1] - v[i]) != 1) {
          ok = 1;
          int t = 1;
          while (abs(v[n-t] - v[n-t-1]) == 1) ++t;
          res.push_back(t);
          v = f(v, res.back());
          //cerr << "ok2\n";
          break;
        }
      }
      if (!ok) {
        vi pos(n);
        for (int i = 0; i < n; ++i) pos[v[i]] = i;
        vi cand(1, -1);
        for (int i = 1; i + 1 < n && !ok; ++i) if (abs(v[i] - v[i+1]) != 1) {
          cand.push_back(i);
          for (int j = v[i] - 1; j <= v[i] + 1; j += 2) if (j >= 0 && j < n && abs(pos[j] - i) != 1) {
            if (pos[j] < i && (pos[j] == 0 || abs(j - v[pos[j] - 1]) != 1)) {
              ok = 1; break;
            }
            if (pos[j] > i && (pos[j] == n-1 || abs(j - v[pos[j] + 1]) != 1)) {
              ok = 1; break;
            }
          }
          if (ok) {
            res.push_back(n - i - 1);
            v = f(v, res.back());
          }
        }
        if (!ok) {
          res.push_back(n - 1 - cand[rand() % cand.size()]);
          v = f(v, res.back());
        }
      }
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
/*  for (int n = 1; n < 2000; ++n) {
    cerr << n << endl;
    vi v(n);
    for (int i = 0; i < n; ++i) v[i] = i;
    random_shuffle(v.begin(), v.end());
    vi res = solve(v);
    //} while (next_permutation(v.begin(), v.end()));
  }*/
  int n;
  string s, t;
  cin >> n >> s >> t;
  vvi sv(26), tv(26);
  vi pos(n);
  for (int i = 0; i < s.size(); ++i) {
    pos[i] = sv[s[i] - 'a'].size();
    sv[s[i]-'a'].push_back(i);
  }
  for (int i = 0; i < s.size(); ++i) tv[t[i]-'a'].push_back(i);
  for (int i = 0; i < 26; ++i) if (sv[i].size() != tv[i].size()) {
    cout << -1 << endl; return 0;
  }
  vi v(n);
  for (int i = 0; i < n; ++i) {
    int x = s[i] - 'a';
    v[i] = tv[x][pos[i]];
  }
  vi res = solve(v);
  cout << res.size() << endl;
  for (int i : res) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
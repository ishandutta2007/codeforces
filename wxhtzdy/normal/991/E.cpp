/**
 *  author: milos
 *  created: 06.01.2021 17:46:39
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 21;

long long f[N];
           
void Calc() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] * i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Calc();
  string s;
  cin >> s;
  vector<int> d;
  int n = (int) s.length();
  for (int i = 0; i < n; i++) {
    d.push_back((int) (s[i] - '0'));
  }
  map<string, int> cnt;
  auto Solve = [&](vector<int> a) {
    sort(a.begin(), a.end());
    string t = "";
    for (int i = 0; i < (int) a.size(); i++) {
      t += (char) ('0' + a[i]);
    }
    if (cnt[t] > 0) {
      return 0LL;
    }
    cnt[t] += 1;
    vector<int> c(10, 0);
    for (int i = 0; i < (int) a.size(); i++) {
      c[a[i]] += 1;
    }
    for (int i = 0; i < 10; i++) {
      if (c[i] == 0) {
        for (int j = 0; j < (int) d.size(); j++) {
          if (d[j] == i) {
            return 0LL;
          }
        }
      }
    }
    long long tmp = f[(int) a.size()]; 
    for (int i = 0; i < 10; i++) {
      tmp /= f[c[i]];
    }    
    if (c[0] > 0) {
      c[0] -= 1;
      long long r = f[(int) a.size() - 1];
      for (int i = 0; i < 10; i++) {
        r /= f[c[i]];
      }
      tmp -= r;
    }
    return tmp;
  };
  long long ans = 0;
  for (int i = 1; i <= (int) (1 << n); i++) {
    vector<int> b;
    for (int j = 0; j < n; j++) {
      if (((1 << j) & i) != 0) {
        b.push_back(d[j]);
      }
    }
    ans += Solve(b);
  }
  cout << ans << '\n';                 
  return 0;
}
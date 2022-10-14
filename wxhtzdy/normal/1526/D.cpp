
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;
 
template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
 
int main() {
  ios::sync_with_stdio(!cin.tie(0));
 
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
 
    int n = (int) s.size();
 
    map<char, int> cnt;
    for (char c : s) cnt[c]++;
 
    vector<int> ord(4);
    iota(ord.begin(), ord.end(), 0);
 
    ll mx = -1;
    string t = "", k = "ANTO";
 
    do {
      string nt = "";
      for (int j = 0; j < 4; j++) {
        for (int i = 0; i < cnt[k[ord[j]]]; i++) {
          nt += k[ord[j]];
        }
      }
 
      vector<int> pos[2][4];
 
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
          if (s[i] == k[j]) {
            pos[0][j].push_back(i);
          }
        }
      }
 
      vector<int> real(n), pp(4);
 
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
          if (nt[i] == k[j]) {
            real[pos[0][j][pp[j]++]] = i;
          }
        }
      }
 
      fenwick<int> fenw(n);
 
      ll dif = 0;
      for (int i = 0; i < n; i++) {
        fenw.modify(real[i], 1);
        if (real[i] < n - 1) real[i] += (fenw.get(n - 1) - fenw.get(real[i]));
        dif += max(0, real[i] - i);
      }
 
      if (dif > mx) {
        mx = dif;
        t = nt;
      }
    } while (next_permutation(ord.begin(), ord.end()));
    cout << t << '\n';
  }
}
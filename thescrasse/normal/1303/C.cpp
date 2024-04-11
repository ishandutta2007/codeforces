#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, direction, check1, kmin, kmax;
string s, alp;
char keyb[100];
map<char, int> used;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  alp = "qwertyuiopasdfghjklzxcvbnm";

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    used.clear();
    for (i = 0; i < 100; i++) {
      keyb[i] = '0';
    }
    check1 = 0;
    cin >> s;
    k = 49;
    kmin = 50;
    kmax = 50;
    direction = 1;
    for (i = 0; i < s.size(); i++) {
      if (used[s[i]] == 0) {
        used[s[i]] = 1;
        k += direction;
        if (keyb[k] == '0') {
          keyb[k] = s[i];
        } else {
          cout << "NO" << endl;
          check1 = 1;
          break;
        }
      } else {
        if (keyb[k - 1] != s[i] && keyb[k + 1] != s[i]) {
          cout << "NO" << endl;
          check1 = 1;
          break;
        } else if (keyb[k - 1] == s[i]) {
          direction = -1;
          k--;
        } else {
          direction = 1;
          k++;
        }
      }
      kmin = min(k, kmin);
      kmax = max(k, kmax);
    }
    if (check1 == 0) {
      cout << "YES" << endl;
      for (i = kmin; i <= kmax; i++) {
        cout << keyb[i];
      }
      for (i = 0; i < 26; i++) {
        if (used[alp[i]] == 0) {
          cout << alp[i];
        }
      }
      cout << endl;
    }
  }

  return 0;
}
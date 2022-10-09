#include <bits/stdc++.h>
using namespace std;
long long n, i, j, k, p, m, c, r, nn1;
string s[1510];
vector<string> thir;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> n >> p;
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  c = 0;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      thir.push_back({});
      for (k = 0; k < p; k++) {
        if (s[i][k] == s[j][k]) {
          thir[c].push_back(s[i][k]);
        } else {
          if (s[i][k] != 'S' && s[j][k] != 'S') {
            thir[c].push_back('S');
          } else if (s[i][k] != 'E' && s[j][k] != 'E') {
            thir[c].push_back('E');
          } else {
            thir[c].push_back('T');
          }
        }
        //cout << thir[c][k];
      }
      //cout << endl;
      c++;
    }
  }
  sort(s, s + n);
  sort(thir.begin(), thir.end());
  r = 0;
  i = 0;
  j = 0;
  while (j < n && i < (n * (n - 1)) / 2) {
    if (thir[i] == s[j]) {
      r++;
      i++;
    } else if (thir[i] > s[j]) {
      j++;
    } else {
      i++;
    }
  }
  cout << r / 3;
  return 0;
}
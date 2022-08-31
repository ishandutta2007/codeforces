/**
 *    author:  tourist
 *    created: 03.09.2017 13:31:39       
**/
#include <bits/stdc++.h>

using namespace std;

string s[5];
string w[5];

void dfs(int i, int j, int cur, int sum) {
  if (i == 3) {
    if (s[i].length() == 1) {
      cout << w[0] << endl;
      cout << w[1] << endl;
      cout << w[2] << endl;
      exit(0);
    }
    return;
  }
  if (j == (int) s[i].length()) {
    stringstream ss;
    ss << (sum + cur);
    ss >> s[i + 1];
    dfs(i + 1, 0, 0, 0);
    return;
  }
  if (j > 0) {
    w[i] += "+";
    w[i] += s[i][j];
    dfs(i, j + 1, s[i][j] - '0', sum + cur);
    w[i].pop_back();
    w[i].pop_back();
  }
  if (cur < 1e7) {
    w[i] += s[i][j];
    dfs(i, j + 1, cur * 10 + (s[i][j] - '0'), sum);
    w[i].pop_back();
  }
}

int main() {
  srand(8753);
  int n;
  cin >> n;
  cin >> s[0];
  while (true) {
    int x = rand() % 999 + 1;
    int sum = 0;
    int i = 0;
    w[0] = "";
    while (i < n) {
      if (i == n - 1 || rand() % 1000 < x) {
        sum += s[0][i] - '0';
        w[0] += s[0][i];
        w[0] += '+';
        i++;
      } else {
        sum += (s[0][i] - '0') * 10 + (s[0][i + 1] - '0');
        w[0] += s[0][i];
        w[0] += s[0][i + 1];
        w[0] += '+';
        i += 2;
      }
    }
    w[0].pop_back();
    stringstream ss;
    ss << sum;
    ss >> s[1];
    dfs(1, 0, 0, 0);
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
const string O[] = {"AND", "OR", "XOR"};

vector<int> expr[N];
string value[N];
int bit[N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<string, int> id;
  id["?"] = -1;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    id[s] = i;

    string e;
    cin >> e;

    string x;
    cin >> x;
    if (x[0] <= '1') {
      value[i] = x;
    } else {
      string op, y;
      cin >> op >> y;
      expr[i] = {id[x], id[y], find(O, O + 3, op) - O};
    }
  }

  string ans_max(m, '0');
  string ans_min(m, '0');

  for (int i = 0; i < m; ++i) {
    array<int, 2> count{};
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (expr[j].empty()) {
          bit[j][k] = value[j][i] - '0';
        } else {
          int x = expr[j][0] == -1 ? k : bit[expr[j][0]][k];
          int y = expr[j][1] == -1 ? k : bit[expr[j][1]][k];
          if (expr[j][2] == 0) {
            bit[j][k] = x & y;
          } else if (expr[j][2] == 1) {
            bit[j][k] = x | y;
          } else {
            bit[j][k] = x ^ y;
          }
        }
        count[k] += bit[j][k];
      }
    }

    if (count[0] < count[1]) {
      ans_max[i] = '1';
    } else if (count[0] > count[1]) {
      ans_min[i] = '1';
    }
  }

  cout << ans_min << "\n";
  cout << ans_max << "\n";
}
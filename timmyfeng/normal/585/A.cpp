#include <bits/stdc++.h>
using namespace std;

const int N = 4000;

int v[N], d[N], p[N], n;
bool in[N];

void check(int);

void cry(int j) {
  in[j] = false;
  for (int i = j + 1; i < n; ++i) {
    if (in[i]) {
      p[i] -= d[j];
      if (p[i] < 0) {
        cry(i);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> d[i] >> p[i];
    in[i] = true;
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (in[i]) {
      ans.push_back(i);
      for (int j = i + 1; j < n && v[i] > 0; ++j) {
        if (in[j]) {
          p[j] -= v[i]--;
        }
      }

      for (int j = i + 1; j < n; ++j) {
        if (in[j] && p[j] < 0) {
          cry(j);
        }
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}
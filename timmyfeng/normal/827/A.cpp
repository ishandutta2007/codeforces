#include <bits/stdc++.h>
using namespace std;

const int N = 2000000;

string substring[N];
int start[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int length = 0;
  fill(start, start + N, -1);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> substring[i] >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      if (start[x - 1] == -1 || substring[start[x - 1]].size() < substring[i].size()) {
        start[x - 1] = i;
      }
      length = max(length, x + (int) substring[i].size() - 1);
    }
  }

  int j = -1;
  int k = 0;
  for (int i = 0; i < length; ++i) {
    if (start[i] != -1) {
      if (j == -1 || (int) substring[start[i]].size() > (int) substring[j].size() - k) {
        j = start[i];
        k = 0;
      }
    }
    cout << (j == -1 || k >= (int) substring[j].size() ? 'a' : substring[j][k++]);
  }
  cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

vector<int> where[N];
int hat[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    where[a].push_back(i);
  }

  for (int i = 0, k = 0; i < n; ++i) {
    if (where[i].size() % (n - i) != 0) {
      cout << "Impossible\n";
      exit(0);
    }

    for (int j = 0; j < (int) where[i].size(); ++j) {
      if (j % (n - i) == 0) {
        ++k;
      }
      hat[where[i][j]] = k;
    }
  }

  cout << "Possible\n";
  for (int i = 0; i < n; ++i) {
    cout << hat[i] << " ";
  }
  cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int partner[2 * N];
int color[2 * N];
bool visited[N];
int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
    partner[a[i]] = b[i];
    partner[b[i]] = a[i];
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int j = i * 2;
      while (!visited[j / 2]) {
        color[j] = 0;
        color[j ^ 1] = 1;
        visited[j / 2] = true;
        j = partner[j ^ 1];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << color[a[i]] + 1 << " " << color[b[i]] + 1 << "\n";
  }
}
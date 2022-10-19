#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], n, m, x, y, cnt[N], col[N], tot = 1;

vector <int> T[N];

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> A[i], T[A[i]].push_back(i);
  for(int i = 0; i < n; ++ i) {
    if(T[i].size() % (n - i) != 0) {
      return 0 * puts("Impossible");
    }
    else {
      for(int j = 0; j < (int) T[i].size(); ++ j)
	col[T[i][j]] = j / (n - i) + tot;
      tot += (T[i].size()) / (n - i);
    }
  }
  puts("Possible");
  for(int i = 1; i <= n; ++ i) printf("%d ", col[i]);
}
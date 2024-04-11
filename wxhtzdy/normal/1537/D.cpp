#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int is_Sqrt(int N) {
  int M = N, cnt = 0;
  while (M % 2 == 0 && M > 1)
    M /= 2, cnt++;
  if (M != 1)
    return false;
  return cnt % 2 == 1;
}

void run_case() {
  int N;
  cin >> N;
  if (N % 2 == 1) {
    cout << "Bob" << '\n';
    return;
  }
  if (N % 2 == 0 && !is_Sqrt(N)) {
    cout << "Alice" << '\n';
    return;
  }
  cout << "Bob\n";
  return;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--)
    run_case();
}
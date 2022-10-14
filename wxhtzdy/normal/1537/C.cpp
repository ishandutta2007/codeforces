#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void run_case() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& i : A) cin >> i;
  sort(A.begin(), A.end());
  int mn = 1e9;
  for (int i = 0; i < N - 1; i++) {
    mn = min(mn, A[i + 1] - A[i]);
  }
  if (N == 2) {
    cout << A[0] << " " << A[1] << '\n';
    return;
  }
  int pos = 1;
  for (int i = 0; i < N - 1; i++) {
    if (A[i + 1] - A[i] == mn) pos = i + 1;
  }
  vector<int> X, Y;
  for (int i = 0; i < N; i++) {
    X.push_back(A[(i + pos) % N]);
  }
  for (int i : X) cout << i << " ";
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--)
    run_case();
}
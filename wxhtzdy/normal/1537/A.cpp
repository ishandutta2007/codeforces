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

  ll sum = accumulate(A.begin(), A.end(), 0LL);

  if (sum < N) {
    cout << 1 << '\n';
    return;
  }
  cout << sum - N << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--)
    run_case();
}
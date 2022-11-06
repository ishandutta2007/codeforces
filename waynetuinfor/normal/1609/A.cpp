#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      while (A[i] % 2 == 0) {
        A[i] /= 2;
        cnt++;
      }
    }
    int p = max_element(A.begin(), A.end()) - A.begin();
    for (int i = 0; i < cnt; ++i) {
      A[p] *= 2;
    }
    cout << accumulate(A.begin(), A.end(), 0LL) << "\n";
  }
}
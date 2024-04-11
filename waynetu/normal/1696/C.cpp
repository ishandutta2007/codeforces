#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int K;
    cin >> K;
    vector<int> B(K);
    for (int i = 0; i < K; ++i) {
      cin >> B[i];
    }

    auto Trans = [&](const vector<int> &A) {
      vector<pair<int, int>> vec;
      for (int u : A) {
        int cnt = 1;
        while (u % M == 0) {
          cnt *= M; 
          u /= M;
        }
        vec.emplace_back(u, cnt);
      }
      vector<pair<int, int64_t>> nres;
      for (int i = 0, j = 0; i < vec.size(); i = j) {
        int64_t s = 0;
        while (j < vec.size() && vec[j].first == vec[i].first) {
          s += vec[j].second;
          j++;
        }
        nres.emplace_back(vec[i].first, s);
      }
      return nres;
    };

    vector<pair<int, int64_t>> va = Trans(A);
    vector<pair<int, int64_t>> vb = Trans(B);
    if (va == vb) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
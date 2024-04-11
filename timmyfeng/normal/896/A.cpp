#include <bits/stdc++.h>
using namespace std;

const string Z = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string S = "What are you doing while sending \"";
const string T = "\"? Are you busy? Will you send \"";
const string U = "\"?";
const int N = 1e5 + 1;

int64_t len[N];

void solve(int n, int64_t k) {
  if (k >= len[n]) {
    cout << ".";
  } else if (n == 0) {
    cout << Z[k];
  } else if (k < int(S.size())) {
    cout << S[k];
  } else {
    k -= S.size();
    if (k < len[n - 1]) {
      solve(n - 1, k);
    } else {
      k -= len[n - 1];
      if (k < int(T.size())) {
        cout << T[k];
      } else {
        k -= T.size();
        if (k < len[n - 1]) {
          solve(n - 1, k);
        } else {
          k -= len[n - 1];
          cout << U[k];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  len[0] = Z.size();
  for (int i = 1; i < N; ++i) {
    len[i] = min(int64_t(1e18), int(S.size() + T.size() + U.size()) + 2 * len[i - 1]);
  }

  int q;
  cin >> q;
  while (q--) {
    int n;
    int64_t k;
    cin >> n >> k;
    solve(n, k - 1);
  }
  cout << "\n";
}
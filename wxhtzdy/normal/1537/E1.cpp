#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void run_case() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  string cur = "", best = "";

  for (int i = 0; i < K; i++)
    best += 'z';

  auto Create = [&](string s) -> string {
    string ret = "";
    while (ret.size() < K)
      ret += s;

    return ret.substr(0, K);
  };

  for (int i = 0; i < N; i++) {
    cur += S[i];

    best = min(best, Create(cur));
  }

  cout << best << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt = 1;
  while (tt--)
    run_case();
}
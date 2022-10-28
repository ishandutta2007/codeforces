#include <bits/stdc++.h>
using namespace std;

const int N = 200'000;

vector<int> layer[N];
bool can_move[N];
int sieve[N];
int mex[N];

bool contains(int a, int b) {
  for (int i = layer[b].size() - 1u; i >= 0; --i) {
    if (can_move[a - layer[b][i]]) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> primes;
  for (int i = 2; i < N; ++i) {
    if (sieve[i] == 0) {
      sieve[i] = i;
      primes.push_back(i);
    }

    for (auto j : primes) {
      if (i * j >= N) {
        break;
      }
      sieve[i * j] = j;
      if (sieve[i] == j) {
        break;
      }
    }

    int j = i;
    int count = 0;
    while (j > 1) {
      j /= sieve[j];
      ++count;
    }
    if (count <= 2) {
      can_move[i] = true;
    }
  }

  int n, f;
  cin >> n >> f;
  can_move[f] = false;

  for (int i = 1; i < N; ++i) {
    while (contains(i, mex[i])) {
      ++mex[i];
    }
    layer[mex[i]].push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    ans ^= mex[b - a];
    ans ^= mex[c - b];
  }

  if (ans == 0) {
    cout << "Bob\n";
    cout << "Alice\n";
  } else {
    cout << "Alice\n";
    cout << "Bob\n";
  }
}
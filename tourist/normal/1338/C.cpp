/**
 *    author:  tourist
 *    created: 12.04.2020 17:26:50       
**/
#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> Get(int bit, long long idx) {
  if (bit == 0) {
    return make_pair(1, 2);
  }
  long long some = 1LL << (bit - 2);
  auto q = Get(bit - 2, idx % some);
  q.first ^= (1LL << (bit - 2));
  q.second ^= (1LL << (bit - 1));
  long long cs = idx / some;
  if (cs == 1) {
    q.first ^= (1LL << (bit - 2));
    q.second ^= (1LL << (bit - 1));
  }
  if (cs == 2) {
    q.first ^= (1LL << (bit - 1));
    q.second ^= (1LL << (bit - 1)) ^ (1LL << (bit - 2));
  }
  if (cs == 3) {
    q.first ^= (1LL << (bit - 1)) ^ (1LL << (bit - 2));
    q.second ^= (1LL << (bit - 2));
  }
  q.first ^= 1LL << bit;
  q.second ^= 1LL << (bit + 1);
  return q;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long idx = (n - 1) / 3;
    long long pos = (n - 1) % 3;
    for (int bit = 0; ; bit += 2) {
      long long here = 1LL << bit;
      if (idx < here) {
        auto p = Get(bit, idx);
        cout << (pos == 0 ? p.first : (pos == 1 ? p.second : (p.first ^ p.second))) << '\n';
        break;
      }
      idx -= here;
    }
  }
  return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

int main()
{
  int N;
  cin >> N;

  string S;
  cin >> S;

  vector<int> info, pos;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'L') {
      info.push_back(-1);
      pos.push_back(i);
    } else if (S[i] == 'R') {
      info.push_back(1);
      pos.push_back(i);
    }
  }

  int res = 0;
  if (info.size() >= 1) {
    if (info[0] == 1) res += pos[0];
    if (info.back() == -1) res += N - pos.back() - 1;
  } else {
    res = N;
  }
  for (int i = 0; i + 1 < info.size(); ++i) {
    if (info[i] == -1) {
      res += pos[i + 1] - pos[i] - 1;
    } else if ((pos[i + 1] - pos[i]) % 2 == 0) {
      ++res;
    }
  }

  cout << res << endl;

  return 0;
}
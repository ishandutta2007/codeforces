#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

int ans[777];

int main() {
  int n;
  long long m;
  cin >> n >> m;
  int l = 0, r = n - 1;
  for (int j = n - 1; j > 0; j--) {
    if (m <= (1LL << (j - 1))) {
      ans[l++] = n - j;
    } else {
      ans[r--] = n - j;
      m -= (1LL << (j - 1));
    }
  }
  ans[l] = n;
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
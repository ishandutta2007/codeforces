#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  int a, b, c, d;
  printf("? 1 2\n"); fflush(stdout); scanf("%d", &a);
  printf("? 2 3\n"); fflush(stdout); scanf("%d", &b);
  printf("? 3 4\n"); fflush(stdout); scanf("%d", &c);
  printf("? 4 5\n"); fflush(stdout); scanf("%d", &d);
  vector<int> v;
  v.push_back(4);
  v.push_back(8);
  v.push_back(15);
  v.push_back(16);
  v.push_back(23);
  v.push_back(42);
  mt19937 g1;
  while(true) {
    if(v[0] * v[1] == a && v[1] * v[2] == b && v[2] * v[3] == c && v[3] * v[4] == d) {
      printf("! %d %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4], v[5]);
      fflush(stdout);
      break;
    }
    shuffle(v.begin(), v.end(), g1);
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
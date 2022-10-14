#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;

ll n, t, k, x, y, m;
ll a[200500];
vector<ll> g[100500];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int a[8] = {1200, 1400, 1600, 1900, 2100, 2400, 2600, 3000};
  cin >> n;
  for (int i = 0; i < 9; i++) {
    if (n < a[i]) {
      cout << a[i] << "\n";
      break;
    }
  }
  return 0;
}
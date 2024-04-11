#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int n, a, b, c, d;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  if(a*n+2*c < b*n+2*d) printf("First\n");
  if(a*n+2*c == b*n+2*d) printf("Friendship\n");
  if(a*n+2*c > b*n+2*d) printf("Second\n");
}
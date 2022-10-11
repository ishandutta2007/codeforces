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
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    if(i%4 == 0 || i%4 == 1) printf("a");
    else printf("b");
  }
  printf("\n");
}
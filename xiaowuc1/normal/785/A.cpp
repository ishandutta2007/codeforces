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

char buf[100];

int main() {
  int n;
  scanf("%d\n", &n);
  int ret = 0;
  while(n--) {
    scanf("%s", buf);
    if(buf[0] == 'T') ret += 4;
    if(buf[0] == 'C') ret += 6;
    if(buf[0] == 'O') ret += 8;
    if(buf[0] == 'D') ret += 12;
    if(buf[0] == 'I') ret += 20;
  }
  printf("%d\n", ret);
}
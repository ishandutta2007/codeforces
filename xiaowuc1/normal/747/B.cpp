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

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;

int n;
char buf[260];

int main() {
  scanf("%d\n%s", &n, buf);
  if(n%4 != 0) {
    printf("===\n");
    return 0;
  }
  int a = 0;
  int c = 0;
  int g = 0;
  int t = 0;
  for(int i = 0; i < n; i++) {
    if(buf[i] == 'A') a++;
    if(buf[i] == 'C') c++;
    if(buf[i] == 'G') g++;
    if(buf[i] == 'T') t++;
  }
  int want = n/4;
  if(a>want || c>want || g>want || t>want) {
    printf("===\n");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    if(buf[i] != '?') continue;
    if(a++ < want) buf[i] = 'A';
    else if(c++ < want) buf[i] = 'C';
    else if(g++ < want) buf[i] = 'G';
    else if(t++ < want) buf[i] = 'T';
  }
  printf("%s\n", buf);
  return 0;
}
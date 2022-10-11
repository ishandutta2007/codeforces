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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

char buf[300];
int n;

int nextNonSpace(int index) {
  while(index < n && buf[index] == '_') index++;
  return index;
}

int endOfWord(int index) {
  assert(buf[index] != '_' && buf[index] != '(' && buf[index] != ')');
  while(index < n && buf[index] != '_' && buf[index] != '(' && buf[index] != ')') index++;
  return index;
}

void solve() {
  int longestOutside = 0;
  int numInside = 0;
  scanf("%d\n", &n);
  gets(buf);
  bool inParen = false;
  for(int i = 0; i < n;) {
    if(buf[i] == '_') {
      i = nextNonSpace(i);
    }
    else {
      if(buf[i] == '(') {
        inParen = true;
        i++;
      }
      else if(buf[i] == ')') {
        inParen = false;
        i++;
      }
      else {
        int lenOf = endOfWord(i) - i;
        assert(lenOf > 0);
        if(inParen) {
          numInside++;
        }
        else {
          longestOutside = max(longestOutside, lenOf);
        }
        i = endOfWord(i);
      }
    }
  }
  printf("%d %d\n", longestOutside, numInside);
}

int main() {
  solve();
  return 0;
}
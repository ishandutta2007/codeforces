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

struct trie {
  int next[26];
  trie() { for (int i = 0; i < 26; ++i) next[i] = -1; }
} T[100050];

int T_size;
void T_init() {
  T_size = 1;
}
int T_alloc() {
  return T_size++;
}
void T_add(int p, char* s) {
  while (*s) {
    int c = *s - 'a';
    if (T[p].next[c] == -1) {
      T[p].next[c] = T_alloc();
    }
    p = T[p].next[c];
    s++;
  }
}

char S[100050];

bool lose1(int);
bool win1(int u) {
  bool res = false;
  for (int i = 0; i < 26; ++i) {
    if (T[u].next[i] != -1) {
      res |= lose1(T[u].next[i]);
    }
  }
  return res;
}

bool lose1(int u) {
  bool res = true;
  for (int i = 0; i < 26; ++i) {
    if (T[u].next[i] != -1) {
      res &= win1(T[u].next[i]);
    }
  }
  return res;
}

bool lose2(int);
bool win2(int u) {
  bool res = false, has = false;
  for (int i = 0; i < 26; ++i) {
    if (T[u].next[i] != -1) {
      has = true;
      res |= lose2(T[u].next[i]);
    }
  }
  return !has ? true : res;
}

bool lose2(int u) {
  bool res = true, has = false;
  for (int i = 0; i < 26; ++i) {
    if (T[u].next[i] != -1) {
      has = true;
      res &= win2(T[u].next[i]);
    }
  }
  return !has ? false : res;
}

int main()
{
  int n = in();
  int k = in();

  T_init();
  for (int i = 0; i < n; ++i) {
    scanf("%s", S);
    T_add(0, S);
  }

  bool w1 = win1(0);
  bool w2 = win2(0);
  int res;

  if (!w1) res = 1;
  else if (w2) res = 0;
  else res = (k - 1) % 2;

  puts(res ? "Second" : "First");

  return 0;
}
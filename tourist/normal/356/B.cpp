#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 1000010;

int ca[N][26], cb[N][26];
char x[N], y[N];

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

int main() {
  long long n, m;
  cin >> n >> m;
  scanf("%s", x);
  scanf("%s", y);
  int a = strlen(x);
  int b = strlen(y);
  int g = gcd(a, b);
  for (int i = 0; i < g; i++)
    for (int j = 0; j < 26; j++) ca[i][j] = cb[i][j] = 0;
  for (int i = 0; i < a; i++) ca[i % g][x[i] - 'a']++;
  for (int i = 0; i < b; i++) cb[i % g][y[i] - 'a']++;
  long long matches = 0;
  for (int i = 0; i < g; i++)
    for (int j = 0; j < 26; j++) matches += (long long)ca[i][j] * cb[i][j];
  long long total = n * a;
  matches *= (n / (b / g));
  cout << (total - matches) << endl;
  return 0;
}
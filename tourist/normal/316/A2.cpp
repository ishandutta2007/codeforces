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

using namespace std;

char s[111111];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool was[255];
  for (char c='A';c<='J';c++) was[c] = false;
  for (int i=0;i<n;i++)
    if (s[i] >= 'A' && s[i] <= 'J') was[s[i]] = true;
  int ans = 1, q = 10;
  for (char c='A';c<='J';c++)
    if (was[c]) {
      if (q == 10 && s[0] >= 'A' && s[0] <= 'J') ans *= 9;
      else ans *= q;
      q--;
    }
  if (s[0] == '?') ans *= 9;
  printf("%d", ans);
  for (int i=1;i<n;i++)
    if (s[i] == '?') printf("0");
  printf("\n");
  return 0;
}
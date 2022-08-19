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

char s[1234567], st[1234567];

int main() {
  scanf("%s", s);
  int e = 0;
  for (int i = 0; s[i]; i++) {
    if (e > 0 && st[e - 1] == s[i]) e--;
    else st[e++] = s[i];
  }
  puts(e ? "No" : "Yes");
  return 0;
}
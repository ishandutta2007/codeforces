#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char s[1111111];

int main() {
  gets(s);
  bool open = false, word = false;
  for (int i=0;s[i];i++)
    if (s[i] == '"') {
      if (open) printf(">\n");
      else printf("<");
      open = !open;
    } else
    if (open) printf("%c", s[i]); else
    if (s[i] != ' ') {
      if (!word) {
        printf("<");
        word = true;
      }
      printf("%c", s[i]);
    } else
    if (word) {
      printf(">\n");
      word = false;
    }
  if (word) printf(">\n");
  return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

int c[3], b[3], ord[3];
char cd[10], bd[10];

bool test(const int bd, const int bm, const int by) {
  if (bm < 1 || bm > 12) return false;
  if (bd < 1 || bd > mon[bm] + ((bm == 2 && by % 4 == 0) ? 1 : 0)) return false;
  if (c[2] - by < 18) return false;
  if (c[2] - by > 18) return true;
  int td = bd, tm = bm;
  if (by % 4 == 0 && td == 29 && tm == 2) {
    if (c[2] % 4 != 0) {
      td = 1;
      tm = 3;
    }
  }
  if (tm > c[1]) return false;
  if (tm < c[1]) return true;
  if (td > c[0]) return false; else return true;
}

int main() {
  gets(cd);
  c[0] = (cd[0] - '0') * 10 + (cd[1] - '0');
  c[1] = (cd[3] - '0') * 10 + (cd[4] - '0');
  c[2] = (cd[6] - '0') * 10 + (cd[7] - '0');
  gets(bd);
  b[0] = (bd[0] - '0') * 10 + (bd[1] - '0');
  b[1] = (bd[3] - '0') * 10 + (bd[4] - '0');
  b[2] = (bd[6] - '0') * 10 + (bd[7] - '0');
  for (int i = 0; i < 3; ++i) ord[i] = i;
  do {
    if (test(b[ord[0]], b[ord[1]], b[ord[2]])) {
      puts("YES");
      return 0;
    }
  } while (next_permutation(ord, ord + 3));
  puts("NO");
  return 0;
}
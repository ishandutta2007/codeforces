#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 510000, B=10;
int n;
int bits0[B],bits1[B];

int operation(int b, int vb, char c) {
  if (c == '|') { return b | vb; }
  else if (c == '^') { return b ^ vb; }
  else if (c == '&') { return b & vb; }
  assert(0);
}

int main() {
  scanf("%d",&n);
  REP(i,B) { bits0[i] = 0; bits1[i] = 1; }
  REP(i,n) {
    char c; int val;
    scanf(" %c%d",&c,&val);
    REP(i,B) {
      int vb = !!(val & 1<<i);
      bits0[i] = operation(bits0[i], vb, c);
      bits1[i] = operation(bits1[i], vb, c);
    }
  }

  int valor = 0, valxor = 0, valand = (1<<B)-1;

  REP(i,B) {
    int b = 1<<i;
    if (bits0[i] == 1 && bits1[i] == 1) { valor |= b; }
    else if (bits0[i] == 0 && bits1[i] == 0) { valand &= ~b; }
    else if (bits0[i] == 1 && bits1[i] == 0) { valxor |= b; }
  }

  printf("3\n");
  printf("| %d\n", valor);
  printf("^ %d\n", valxor);
  printf("& %d\n", valand);
}
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int n,s,d;

int main() {
  scanf("%d",&n);
  int t = 0;
  REP(i,n) {
    scanf("%d%d",&s,&d);
    int p = s;
    while (p <= t) { p += d; }
    t = p;
  }
  printf("%d\n", t);
}
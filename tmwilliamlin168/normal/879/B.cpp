#include <algorithm>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 1000;
int n;
long long k;
int a[N],win[N];

int main() {
  scanf("%d%I64d",&n,&k);
  REP(i,n) {
    scanf("%d", &a[i]); --a[i];
  }
  while (true) {
    if (a[1] > a[0]) { swap(a[1], a[0]); }
    if (++win[a[0]] >= k || a[0] == n-1) { printf("%d\n", a[0]+1); return 0; }
    rotate(a+1,a+2,a+n);
  }
}
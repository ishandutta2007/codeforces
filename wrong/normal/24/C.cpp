#include<cstdio>
#include<set>
#include<vector>
#include<iostream>

using namespace std;

typedef int ll;
typedef pair<ll, ll> pt;

int ax[100000], ay[100000];
set<pt> P[100000];
pt last[100000];

int main()
{
  int n;
  long long j;
  scanf("%d%I64d", &n, &j);
  ll Mx, My;
  scanf("%d%d", &Mx, &My);
  for(int i=0; i<n; ++i)
    scanf("%d%d", &ax[i], &ay[i]);
  int next = 0, cnt = 0;
  while(true) {
    if(P[next].find(pt(Mx, My)) != P[next].end()) break;
    P[next].insert(pt(Mx, My));
    last[next] = pt(Mx, My);
    Mx += (ax[next] - Mx) * 2;
    My += (ay[next] - My) * 2;
    next = (next+1) % n;
    cnt++;
    if(cnt == j) {
      printf("%d %d\n", Mx, My);
      return 0;
    }
  }
  j %= cnt;
  while(j--) {
    Mx += (ax[next] - Mx) * 2;
    My += (ay[next] - My) * 2;
    next = (next+1) % n;
  }
  printf("%d %d\n", Mx, My);
  return 0;
}
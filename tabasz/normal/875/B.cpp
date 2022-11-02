#include<bits/stdc++.h>
using namespace std;
# ifdef DEB
# define debug(...) fprintf(stderr, __VA_ARGS__)
# else
# define debug(...)
#endif
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define VI vector<int>
#define VPI vector<PII>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define ALL(x) (x).begin(), (x).end()
#define siz(V) ((int)V.size())
const int M = 1024 * 512;

int n;
int T[2 * M];

void add(int v)
{
  v += M;
  T[v] += 1;
  while (v > 1)
  {
    v /= 2;
    T[v] = T[2 * v] + T[2 * v + 1];
  }
}

int lastZ(int v, int il)
{
  if (v >= M)
  {
    return v - M;
  }
  if (T[2 * v + 1] == il / 2)
  {
    return lastZ(2 * v, il / 2);
  }
  return lastZ(2 * v + 1, il / 2);
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = n + 1; i < M; i++)
  {
    add(i);
  }
  printf("1 ");
  for (int i = 1; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    add(a);
    int ind = lastZ(1, M);
    int il = n - ind;
    printf("%d ", 1 + i - il);
  }
  printf("\n");
  return 0;
}
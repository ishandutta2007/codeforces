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
const int  M = 1024 * 256;

vector<int> V[10006];
PII K[M];
int W[M], T[M];
int res;
int ziom[M];
bool B[M];
int n, m;

int find(int a)
{
  if (T[a] == a)
  {
    return a;
  }
  return T[a] = find(T[a]);
}

void onion(int a, int b)
{
  T[find(a)] = find(b);
}

bool add(int ind)
{
  int a = find(K[ind].F), b = find(K[ind].S);
  if (a == b)
  {
    if (!B[a])
    {
      B[a] = true;
      return true;
    }
    return false;
  }
  if (!B[a] && !B[b])
  {
    onion(a, b);
    return true;
  }
  if (!B[a])
  {
    B[a] = true;
    return true;
  }
  if (!B[b])
  {
    B[b] = true;
    return true;
  }
  return false;
}

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
    T[i] = i;
  }
  for (int i = 1; i <= m; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    V[c].PB(i);
    K[i] = MP(a, b);
    W[i] = c;
  }
  for (int i = 10000; i > 0; i--)
  {
    for (int j = 0; j < siz(V[i]); j++)
    {
      if (add(V[i][j]))
      {
        res += i;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
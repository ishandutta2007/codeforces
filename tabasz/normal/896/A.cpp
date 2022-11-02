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
const int M = 1e5;
const LL inf = 1e18;

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
string r = a + s + b + s + c;
LL L[100005];
int maxi = M + 1;

char solve(int n, LL k)
{
  if (maxi > n && k >= L[n])
  {
    return '.';
  }
  if (n == 0)
  {
    return s[k];
  }
  if (k < (LL)siz(a))
  {
    return a[k];
  }
  if (k < (LL)siz(a) + L[n - 1])
  {
    return solve(n - 1, k - siz(a));
  }
  if (k < (LL)siz(a) + L[n - 1] + siz(b))
  {
    return b[k - siz(a) - L[n - 1]];
  }
  if (k < (LL)siz(a) + L[n - 1] * 2 + siz(b))
  {
    return solve(n - 1, k - siz(a) - siz(b) - L[n - 1]);
  }
  return c[k - (LL)siz(a) - L[n - 1] * 2 - siz(b)];
}

int main()
{
  //ios_base::sync_with_stdio(0);
  //cout<< s << '\n';
  //cout<< r << '\n';
  int q;
  scanf("%d", &q);
  L[0] = siz(s);
  L[1] = siz(r);
  for (int i = 2; i <= M; i++)
  {
    L[i] = siz(a) + siz(b) + L[i - 1] * 2 + siz(c);
    if (L[i] > inf)
    {
      L[i] = inf * 2;
      maxi = min(maxi, i);
    }
  }
  //debug("%d %d\n", maxi, L[1]);
  while (q--)
  {
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    k--;
    printf("%c", solve(n, k));
  }
  printf("\n");
  return 0;
}
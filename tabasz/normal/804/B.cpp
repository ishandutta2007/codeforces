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
const LL mod = 1e9 + 7;

string s;
int res;
LL P[1000005];

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> s;
  int n = s.length();
  P[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    P[i] = (P[i - 1] * 2) % mod;
  }
  int li = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'a')
    {
      li++;
    }
  }
  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == 'b')
    {
      res += P[li] - 1;
      if (res >= mod)
      {
        res -= mod;
      }
      if (res < 0)
      {
        res += mod;
      }
    }
    else
    {
      li--;
    }
  }
  cout<< res << '\n';
  return 0;
}
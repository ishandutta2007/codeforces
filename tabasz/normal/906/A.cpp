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
const int M = 200;

int n;
bool B[M], done;
int all, must, tmp = 26;

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n;
  for (int i = 0; i < n; i++)
  {
    string a, b;
    cin>> a >> b;
    if (a[0] == '.')
    {
      for (auto c : b)
      {
        if (!B[(int)c])
        {
          B[(int)c] = true;
          tmp--;
        }
      }
    }
    if (a[0] == '!')
    {
      all++;
      if (!done)
      {
        must++;
      }
      for (int i = 0; i < 26; i++)
      {
        bool boo = false;
        for (auto c : b)
        {
          if (c == (char)((int)'a' + i))
          {
            boo = true;
            break;
          }
        }
        if (!boo)
        {
          if (!B[(int)'a' + i])
          {
            B[(int)'a' + i] = true;
            tmp--;
          }
        }
      }
    }
    if (a[0] == '?')
    {
      if (i != n - 1)
      {
        all++;
        if (!done)
        {
          must++;
        }
        if (!B[(int)b[0]])
        {
          B[(int)b[0]] = true;
          tmp--;
        }
      }
    }
    if (tmp <= 1)
    {
      done = true;
    }
  }
  cout<< all - must << "\n";
  return 0;
}
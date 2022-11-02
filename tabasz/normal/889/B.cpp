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
const int M = 1024 * 128;

string s[M];
int n;
int T[M][30];
int out[30], in[30];
vector<char> R;
bool B[30][30];
bool vis[30], jest[30];

void DFS(int v)
{
  vis[v] = 1;
  R.PB((char)(v + (int)'a'));
  for (int i = 0; i < 26; i++)
  {
    if (!vis[i] && B[v][i])
    {
      DFS(i);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n;
  for (int i = 0; i < n; i++)
  {
    cin>> s[i];
    for (int j = 0; j < siz(s[i]); j++)
    {
      int lol = (int)s[i][j] - (int)'a';
      jest[lol] = 1;
      T[i][(int)s[i][j] - (int)'a']++;
      if (T[i][(int)s[i][j] - (int)'a'] > 1)
      {
        cout<< "NO\n";
        return 0;
      }
      if (j < siz(s[i]) - 1)
      {
        int qwe = (int)s[i][j + 1] - (int)'a';
        if (!B[lol][qwe])
        {
          out[lol]++;
          in[qwe]++;
        }
        B[lol][qwe] = 1;
      }
    }
  }
  for (int i = 0; i < 26; i++)
  {
    if (out[i] > 1 || in[i] > 1)
    {
      cout<< "NO\n";
      return 0;
    }
  }
  for (int i = 0; i < 26; i++)
  {
    if (!vis[i] && jest[i] && in[i] == 0)
    {
      DFS(i);
    }
  }
  int lol = 0;
  for (int i = 0; i < 26; i++)
  {
    if (jest[i])
    {
      lol++;
    }
  }
  if (siz(R) != lol)
  {
    cout<< "NO\n";
    return 0;
  }
  for (int i = 0; i < siz(R); i++)
  {
    cout<< R[i];
  }
  cout<< "\n";
  return 0;
}
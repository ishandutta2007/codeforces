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
const int p=10007;
const int mod=1e9+7;

int a, b, c, n, m;

set<int> se;

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n >> m;
  a=n;
  b=m;
  REP(i, n)
  {
    string s;
    cin>> s;
    int l=s.size();
    LL has=0;
    REP(j, l)
      has=(has*p+(LL)s[j]+100)%mod;
    se.insert(has);
  }
  REP(i, m)
  {
    string s;
    cin>> s;
    int l=s.size();
    LL has=0;
    REP(j, l)
      has=(has*p+(LL)s[j]+100)%mod;
    if(se.find(has)!=se.end())
    {
      a--;
      b--;
      c++;
    }
  }
  if(c%2==1)
    b--;
  if(a>b)
    cout<< "YES\n";
  else
    cout<< "NO\n";
  return 0;
}
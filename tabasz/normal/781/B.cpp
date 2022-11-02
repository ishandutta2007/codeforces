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

int n;
vector<int> V[30*30];
PII X[1005];
char C[1005][2], R[1005];
string a, b;
vector<int> vec;
bool used[30][3];//left, forbidden, right

bool bad(int ind)
{
  int v=vec[ind];
  return ((used[X[v].F][0] || used[X[v].F][1] || used[X[v].F][2]) && (used[X[v].S][0] || used[X[v].S][2] || used[X[v].F][0])); 
}

bool jebaj(int ind)
{
  //debug("                       %d\n", ind);
  if(ind>=siz(vec))
    return true;
  for(int i=ind; i<siz(vec); i++)
    if(bad(i))
      return false;
  int v=vec[ind];
  if(!used[X[v].F][0] && !used[X[v].F][1] && !used[X[v].F][2])
  {
    used[X[v].F][0]=1;
    R[v]=(char)(X[v].F+(int)'A');
    if(jebaj(ind+1))
      return true;
    used[X[v].F][0]=0;
  }
  if(!used[X[v].S][0] && !used[X[v].S][2] && !used[X[v].F][0])
  {
    bool boo=0;
    used[X[v].S][2]=1;
    if(!used[X[v].F][1])
      boo=1;
    used[X[v].F][1]=1;
    R[v]=(char)(X[v].S+(int)'A');
    if(jebaj(ind+1))
      return true;
    used[X[v].S][2]=0;
    if(boo)
      used[X[v].F][1]=0;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n;
  REP(i, n)
  {
    cin>> a >> b;
    X[i]=MP((int)a[2]-(int)'A', (int)b[0]-(int)'A');
    //debug("     %d\n", ((int)a[0]-(int)'A')*26+(int)a[1]-(int)'A');
    //debug("%c %c\n", a[2], b[0]);
    V[((int)a[0]-(int)'A')*26+(int)a[1]-(int)'A'].PB(i);
    C[i][0]=a[0];
    C[i][1]=a[1];
  }
  REP(i, 26*26)
  {
    if(siz(V[i])>26)
    {
      cout<< "NO\n";
      return 0;
    }
    REP(j, 26)
    {
      used[j][0]=0;
      used[j][1]=0;
      used[j][2]=0;
    }
    vec.clear();
    REP(j, siz(V[i]))
      vec.PB(V[i][j]);
    //if(siz(V[i])>0)
     // debug("%d %d\n", i, siz(V[i]));
    if(siz(V[i])>0 && !jebaj(0))
    {
      //cout<< i << " ";
      cout<< "NO\n";
      return 0;
    }
  }
  cout<< "YES\n";
  REP(i, n)
    cout<< C[i][0] << C[i][1] << R[i] << '\n';
  return 0;
}
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

string a, b;
bool B[200005];
int n, nn;
int T[200005];

bool check(int m)
{
  REP(i, n)
    B[i]=0;
  REP(i, m)
    B[T[i]-1]=1;
  int ind=0, pos=0;
  while(ind<nn && pos<n)
  {
    if(!B[pos] && a[pos]==b[ind])
      ind++;
    pos++;
  }
  //debug("%d %d %d\n", m, ind, pos);
  if(ind==nn)
    return true;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> a >> b;
  n=a.size();
  nn=b.size();
  REP(i, n)
    cin>> T[i];
  int st=0, en=n, mid=(st+en)/2, r=0;
  while(st<=en)
  {
    if(check(mid))
    {
      r=max(r, mid);
      st=mid+1;
    }
    else
      en=mid-1;
    mid=(st+en)/2;
  }
  cout<< r << "\n";
  return 0;
}
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <deque>

#include <algorithm>
#include <utility>
#include <complex>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0; i<n; i++)
#define F(i,L,R) for(int i=L; i<R; i++)

#define printA(a,L,R) F(puf,L,R) cout << a[puf] << (puf==(R-1)?'\n':' ')
#define printV(a) printA(a,0,a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef long double ld;

typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ld> vld;

#define PI 3.1415926535897932384626
#define INF 2001000009
#define EPS 1e-8
#define MAXN 100007
#define MOD 1000000007

int main() { // ios_base::sync_with_stdio(0); cin.tie(0);

  ll a,b;
  cin >> a >> b;
  ll sumq = 0;
  ll tmpq = a+1;
  tmpq*=b;
  tmpq%=MOD;
  if (tmpq%2==0) tmpq/=2;
  else tmpq = (tmpq+MOD)/2;
  tmpq++;
  tmpq*=a;
  tmpq%=MOD;

  sumq = (b-1)*b;
  sumq/=2;
  sumq%=MOD;
  sumq*=tmpq;
  sumq%=MOD;
  cout << sumq << endl;

  return 0;
}
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

int n,m;

int main() { // ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  string s1,s2;
  cin >> s1;
  cin >> s2;
  if ((s1[0]=='<' && s1[s1.size()-1]=='>' && s2[0]=='v' && s2[s2.size()-1]=='^')
      || (s1[0]=='>' && s1[s1.size()-1]=='<' && s2[0]=='^' && s2[s2.size()-1]=='v'))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <deque>

#include <algorithm>
#include <utility>
#include <complex>

//#include <bits/stdc++.h> //include everything

using namespace std;

#define maX(a,b) ((a)>(b)?(a):(b)) //use only with computed things
#define miN(a,b) ((a)<(b)?(a):(b))
#define abS(a)   ((a)<0?(-(a)):(a))
#define bitcount __builtin_popcount
#define gcd      __gcd

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define INF 2001000009
#define PI 3.1415926535897932384626
#define EPS 1e-8

#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<n; i++)
#define F(i,L,R) for(int i=L; i<R; i++)
#define inrange(i,L,R) ((L)<=(i)&&(i)<=(R))
#define IN(c,x) ((c).find(x) != (c).end())
#define bit(x,i) ((x)&(1<<(i)))

#define def1(a) int (a); scanf("%d",&(a))
#define def2(a,b) int (a),(b); scanf("%d %d",&(a),&(b))
#define def3(a,b,c) int (a),(b),(c); scanf("%d %d %d",&(a),&(b),&(c))
#define def4(a,b,c,d) int (a),(b),(c),(d); scanf("%d %d %d %d",&(a),&(b),&(c),&(d))
#define def5(a,b,c,d,e) int (a),(b),(c),(d),(e); scanf("%d %d %d %d %d",&(a),&(b),&(c),&(d),&(e))
#define printA(a,L,R) F(zz49,L,R) cout << a[zz49] << (zz49==(R-1)?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

#define MAXN 1000007
int dp[MAXN];

// memset(dist, 127, sizeof dist);
// memset(dp, -1, sizeof dp);
// memset(arr, 0, sizeof arr);

int main() { //FASTIO

  def2(n,m);
  int count=0;
  while (count<n+count/m) count++;
  cout << count << endl;

  return 0;

}
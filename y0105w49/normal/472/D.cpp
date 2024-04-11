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
#define MAXN 2005

ll distmat[MAXN][MAXN];
int n;

int disttop[MAXN];
int inset[MAXN];
int disttoset[MAXN];

int main() { ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  REP(i,n) REP(j,n) cin >> distmat[i][j];

  REP(i,n) REP(j,i) if (distmat[i][j]!=distmat[j][i] || distmat[i][j] <= 0) { cout << "NO" << endl; return 0; }
  REP(i,n) if (distmat[i][i]!=0) { cout << "NO" << endl; return 0; }

  inset[0]=1;
  REP(i,n) disttoset[i]=distmat[i][0];
  REP(zz,n-1) {
    int nearest = INF;
    int nearestindex = -1;
    REP(i,n) {
      if (inset[i]==0 && disttoset[i] < nearest) {
        nearest = disttoset[i]; nearestindex=i;
      }
    }
    int parent = -1;
    REP(i,n) {
      if (inset[i]==1 && disttoset[nearestindex] >= distmat[i][nearestindex]) {
        if (parent != -1 || disttoset[nearestindex] > distmat[i][nearestindex]) {
          cout << "NO" << endl; return 0;
        }
        parent = i;
      }
    }
    REP(i,n) {
      if (inset[i]==1 && nearest+distmat[parent][i]!=distmat[i][nearestindex]) {
        cout << "NO" << endl; return 0;
      }
    }
    REP(i,n) {
      if (i!=nearestindex && inset[i]==0 && disttoset[i] >= distmat[i][nearestindex]) {
        if (disttoset[i]==distmat[i][nearestindex]) {
          cout << "NO" << endl; return 0;
        }
        disttoset[i]=distmat[i][nearestindex];
      }
    }
    inset[nearestindex]=1;
  }
  cout << "YES" << endl;

  return 0;
}
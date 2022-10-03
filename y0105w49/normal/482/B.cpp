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
#define MAXN 131072
#define MOD 1000000007

int a[MAXN];
int n,m;
int ortree[MAXN*2], andtree[MAXN*2];
iii reqs[MAXN];

int orem(int i) {
  int sumq = 0;
  int index = MAXN+i;
  while (index>0) {
    sumq |= ortree[index];
    index/=2;
  }
  return sumq;
}

void fixands(int i) {
  int index = MAXN+i;
  int andq = andtree[index];
  while (index>0) {
    andtree[index]&=andq;
    index /= 2;
  }
}

int getand(int l, int r) {
  if (l>r) return 2147483647;
  if (l==r) return andtree[MAXN+l];
  int index = MAXN+l;
  int powq = 1;
  while (index%2==0 && powq*2+l<=r+1) {
    index/=2; powq*=2;
  }
  return getand(l+powq,r)&andtree[index];
}

void pushors(int l, int r, int q) {
  if (l>r) return;
  if (l==r) ortree[MAXN+l]|=q;
  int index = MAXN+l;
  int powq = 1;
  while (index%2==0 && powq*2+l<=r+1) {
    index/=2; powq*=2;
  }
  pushors(l+powq,r,q);
  ortree[index]|=q;
}

int main() { // ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  int l,r,q;
  REP(i,m) {
    cin >> l >> r >> q;
    --l; --r;
    pushors(l,r,q);
    reqs[i]=mp(q,mp(l,r));
  }
  REP(i,n)
    a[i]=orem(i);

  REP(i,n)
    andtree[MAXN+i]=a[i];

  REP(i,MAXN) andtree[i]=2147483647;

  REP(i,n)
    fixands(i);

  int good = 1;
  REP(i,m)
    if (reqs[i].fi != getand(reqs[i].se.fi,reqs[i].se.se))
      good = 0;

  if (good == 0) {
    cout << "NO" << endl; return 0;
  }
  cout << "YES" << endl;
  printA(a,0,n);

  return 0;
}
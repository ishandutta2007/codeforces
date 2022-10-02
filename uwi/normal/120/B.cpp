#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

#define MP make_pair
#define PB push_back
#define SZ(xs) int((xs).size())
#define ELEM(x,xs) ((xs).find(x)!=(xs).end())
#define SORT(xs) sort((xs).begin(),(xs).end())
#define FOREACH(it,xs) for(typeof((xs).begin()) it=(xs).begin();it!=(xs).end();++it)

#define PMOD(a,b) (((a)%(b)+(b))%(b))

#define DUMP(x) cerr << #x << " = " << (x) << endl;

const double EPS = 1e-9;
const double PI = acos(-1.);

template <class T> inline T sq(T x) {return x*x;}

template <class T> inline void upd_min(T &lhs, T rhs) {if(lhs>rhs)lhs=rhs;}
template <class T> inline void upd_max(T &lhs, T rhs) {if(lhs<rhs)lhs=rhs;}

void solve() {

  ifstream in;
  in.open("input.txt");
  ofstream out;
  out.open("output.txt");

  int n, k;
  in >> n >> k;
  int a[1<<11];
  REP(i,n) {
    int _a;
    in >> _a;
    a[i] = a[n+i] = _a;
  }
  for (int i = k-1; ; ++i) {
    if (a[i]) {
      out << i%n+1 << endl;
      break;
    }
  }

}

int main() {

  solve();

  return 0;

}
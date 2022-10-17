#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve(int tc) {
  int n, m;
  cin >> n >> m;

  auto DIG = [&](int x, int y) {
    cout << "DIG " << x+1 << " " << y+1 << endl;
    cin >> x;
    return x;
  };
  auto SCAN = [&](int x, int y) {
    cout << "SCAN " << x+1 << " " << y+1 << endl;
    cin >> x;
    return x;
  };

  int A = SCAN(0,0); // = r1+r2+c1+c2
  int B = SCAN(0,m-1) - 2*(m-1); // = r1+r2-c1-c2

  assert((A+B)%2 == 0);

  int R = (A+B)/2; // = r1+r2
  int C = (A-B)/2; // = c1+c2

  int RR = SCAN(R/2,0) - C; // = r2-r1
  int CC = SCAN(0,C/2) - R; // = c2-c1
  assert((RR+R)%2 == 0);
  assert((CC+C)%2 == 0);

  int r1 = (R-RR)/2;
  int r2 = (R+RR)/2;
  int c1 = (C-CC)/2;
  int c2 = (C+CC)/2;

  if(DIG(r1,c1)) assert(DIG(r2,c2));
  else {
    assert(DIG(r1,c2));
    assert(DIG(r2,c1));
  }
}

int main() {
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}



/*
 * with 2 queries can find:
 * r1 + r2 + c1 + c2 = A
 * r1 + r2 - c1 - c2 = B
 *
 *
 * hence also
 * r1+r2
 * c1+c2
 *
 * want: r1-r2 with another 2 queries?
 *
 * */

/*
 * 1 2
 * 1 3
 *
 * */
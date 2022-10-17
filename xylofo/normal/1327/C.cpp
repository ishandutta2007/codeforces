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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  string moves = "";
  moves += string(n-1,'U');
  moves += string(m-1,'L');
  rep(i,0,n) {
    moves += string(m-1,i%2 == 0 ? 'R' : 'L');
    moves += 'D';
  }
  cout << sz(moves) << endl;
  cout << moves << endl;
}
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
  int n,k;
  cin>>n>>k;
  if(k%2 != n%2) { cout << "NO" << endl; return; }
  ll a = 1, b = 0;
  rep(i,0,k) {
    b += a;
    a += 2;
    if(b > n) { cout << "NO" << endl; return; }
  }
  cout << "YES" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}
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
  int b, k;
  cin >> b >> k;
  int ans = 0;
  int pw = 1;
  vi a(k);
  rep(i,0,k) cin>>a[i];
  reverse(all(a));
  rep(i,0,k) {
    ans = (ans+a[i]*pw)%2;
    pw = (pw*b)%2;
  }
  cout << (ans ? "odd" : "even") << endl;
}
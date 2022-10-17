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
  int n;
  cin >> n;
  vi a(n), b(n);
  rep(i,0,n) cin>>a[i];
  rep(i,0,n) cin>>b[i];
  vi da(n-1), db(n-1);
  rep(i,0,n-1) da[i] = a[i+1]-a[i];
  rep(i,0,n-1) db[i] = b[i+1]-b[i];
  sort(all(da));
  sort(all(db));
  if(da == db && a[0] == b[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
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
  vi lens;
  int last_b = -1;
  rep(i,0,n) {
    int b;
    cin>>b;
    if(last_b != -1) lens.emplace_back(b-last_b);
    last_b = b+1;
  }
  sort(all(lens));
  int ans = n;
  int segs = n;
  rep(i,0,max(0,n-k)) ans += lens[i];
  cout << ans << endl;
}
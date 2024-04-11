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
  int t,n,m;
  cin>>t;
  rep(_,0,t) {
    cin >> n >> m;
    if(n == 1 && m == 1) cout << 0;
    else if(n == 1 || m == 1) cout << 1;
    else cout << 2;
    cout << "\n";
  }
}
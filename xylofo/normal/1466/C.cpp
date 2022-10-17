#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  string s;
  cin>>s;
  int n = sz(s);
  int cnt = 0;
  rep(i,0,n) {
    if((i && s[i] == s[i-1]) || (i >= 2 && s[i] == s[i-2])) {
      s[i] = '?';
      ++cnt;
    }
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}
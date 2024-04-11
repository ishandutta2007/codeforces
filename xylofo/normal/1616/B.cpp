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
  int n;
  cin >> n;
  string s;
  cin>>s;
  bool first = true;
  int len = 1;
  while(len < n) {
    if(s[len] < s[len-1]) {
      first = false;
      ++len;
      continue;
    }
    else if(s[len] > s[len-1]) {
      break;
    }
    else if(s[len] == s[len-1]) {
      if(first) break;
      else len++;
    }
    else assert(false);
  }

  s = s.substr(0,len);

  string ans = "";
  ans += s;
  reverse(all(s));
  ans += s;
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}
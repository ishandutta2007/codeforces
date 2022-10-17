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
  int a, b, ab, ba;
  cin >> a >> b >> ab >> ba;
  string s;
  cin>>s;
  if(count(all(s),'A') != a+ab+ba) {
    cout << "NO" << "\n";
    return;
  }
  if(count(all(s),'B') != b+ab+ba) {
    cout << "NO" << "\n";
    return;
  }
  int free = 0;
  string q = "";

  vi AB, BA;
  auto collapse = [&](){
    //debug(q);
    int r = sz(q);
    if(r % 2 == 1) free += r/2;
    else {
      if(q[0] == 'B') {
        BA.emplace_back(r);
      }
      if(q[0] == 'A') {
        AB.emplace_back(r);
      }
    }
    q = "";
  };

  rep(i,0,sz(s)) {
    if(sz(q) && q.back() == s[i]) {
      collapse();
    }
    q += s[i];
  }
  collapse();

  sort(all(BA));
  sort(all(AB));
  for(int r : BA) {
    int t = min(r/2, ba);
    ba -= t;
    r -= t*2;
    free += (r-1)/2;
  }
  for(int r : AB) {
    int t = min(r/2, ab);
    ab -= t;
    r -= t*2;
    free += (r-1)/2;
  }

  //debug(s, free, ab, ba);

  if(free < ab + ba) {
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}
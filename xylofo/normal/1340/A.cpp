#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t, n;
  cin >> t;
  rep(_,0,t) {
    cin >> n;
    vi v(n);
    trav(x, v) cin >> x;
    int small = 0, big = 0;
    int lst = 0;
    bool bad = false;
    for(int i = n; i--;) {
      if(lst == small) {
        small = big + 1;
        big = v[i];
        lst = v[i];
      }
      else {
        if(v[i] != lst-1) bad = true;
        lst = v[i];
      }
    }
    cout << (bad ? "No" : "Yes") << endl;
  }
}
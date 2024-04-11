#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
  int tt; cin >> tt;

  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for(int i = 0; i < sz(s); ++i) {
      if(s[i] != t[i])
        ++ans;
    }
    cout << ans << "\n";
  }
}
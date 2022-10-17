#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  bool is_locked = false;
  string color = "blue";
  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "lock") {
      is_locked = true;
    } else if (cmd == "unlock") {
      is_locked = false;
    } else if (!is_locked) {
      color = cmd;
    }
  }
  cout << color << '\n';
}
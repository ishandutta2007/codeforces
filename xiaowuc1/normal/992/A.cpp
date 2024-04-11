#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  set<int> ret;
  while(n--) {
    int t;
    cin >> t;
    if(t) ret.insert(t);
  }
  cout << ret.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
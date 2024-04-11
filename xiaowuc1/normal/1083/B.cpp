#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300005;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int len;
  ll need;
  cin >> len >> need;
  string a, b;
  cin >> a >> b;
  ll cnt = 0;
  bool done = false;
  ll ret = 0;
  for(int i = 0; i < len; i++) {
    if(done) {
      ret += need;
    }
    else {
      cnt *= 2;
      if(b[i] == 'b') cnt++;
      if(a[i] == 'b') cnt--;
      if(cnt >= need) done = true;
      ret += min(need, cnt+1);
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
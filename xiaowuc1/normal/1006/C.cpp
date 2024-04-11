#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
ll l[1000000];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int lhs = 0;
  int rhs = n-1;
  ll ret = 0;
  ll lS = 0;
  ll rS = 0;
  while(lhs <= rhs) {
    if(lS == rS) {
      ret = lS;
      lS += l[lhs++];
    }
    else if(lS < rS) {
      lS += l[lhs++];
    }
    else {
      rS += l[rhs--];
    }
  }
  if(lS == rS) ret = lS;
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
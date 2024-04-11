#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int l[1000000];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  int lhs = 0;
  int ret = 0;
  for(int i = 0; i < n; i++) {
    if(i && 2*l[i-1] < l[i]) lhs = i;
    ret = max(ret, i-lhs+1);
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}
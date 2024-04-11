#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int l[100005];
int n, m, k;

void solve() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  vector<int> diff;
  for(int i = 1; i < n; i++) {
    diff.push_back(l[i] - l[i-1] - 1);
  }
  sort(diff.begin(), diff.end());
  reverse(diff.begin(), diff.end());
  int ret = l[n-1] - l[0] + 1;
  for(int i = 0; i < k-1 && i < diff.size(); i++) {
    ret -= diff[i];
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
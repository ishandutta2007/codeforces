#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int l[100005];
int t[100005];

void solve() {
  int n, maxT, a;
  cin >> n >> maxT >> a;
  for(int i = 0; i < n; i++) cin >> l[i] >> t[i];
  int ret = 0;
  ret += l[0] / a;
  ret += (maxT - l[n-1] - t[n-1]) / a;
  for(int i = 1; i < n; i++) {
    ret += (l[i] - l[i-1] - t[i-1]) / a;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
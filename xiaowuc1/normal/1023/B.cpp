#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  ll n, k;
  cin >> n >> k;
  ll ret = (k-1)/2;
  ll largest = (k-1)/2;
  ll smallest = max(1LL, k-n);
  cout << max(0LL, largest - smallest + 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
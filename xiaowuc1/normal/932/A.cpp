#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  string a;
  cin >> a;
  for(int i = 0; i < a.size(); i++) cout << a[i];
  for(int i = 0; i < a.size(); i++) cout << a[a.size()-1-i];
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
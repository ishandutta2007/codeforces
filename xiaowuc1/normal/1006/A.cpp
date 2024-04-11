#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x%2==0) x--;
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
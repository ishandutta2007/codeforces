#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, pill> pllpill;
typedef pair<pii, pii> pipii;

int lhs[105];
int rhs[105];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> lhs[i] >> rhs[i];
  }
  int now;
  cin >> now;
  int ret = n;
  for(int i = 0; i < n; i++) {
    if(now > rhs[i]) ret--;
    else break;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
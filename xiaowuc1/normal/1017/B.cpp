#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  ll zz = 0;
  ll zo = 0;
  ll oz = 0;
  ll oo = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == '0' && b[i] == '0') zz++;
    if(a[i] == '0' && b[i] == '1') zo++;
    if(a[i] == '1' && b[i] == '0') oz++;
    if(a[i] == '1' && b[i] == '1') oo++;
  }
  ll ret = 0;
  ret += zz * oo;
  ret += zz * oz;
  ret += zo * oz;
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
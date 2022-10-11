#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  int a = 1;
  int b = 1;
  int c = n-2;
  if(c%3==0) { a++; c--;}
  cout << a << " " << b << " " << c << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
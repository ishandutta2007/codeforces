#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int n;
string a, b;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  cin >> a; cin >> b;
  sort(a.begin(), a.end(), greater<char>()); sort(b.begin(), b.end(), greater<char>());
  int i = 0, j = 0, ii = n - 1, jj = n - 1, ans1 = 0, ans2 = 0;
  while (i <= ii && j <= jj) {
    if (a[i] <= b[j]) ++i, ++j;
    else ++i, --jj, ++ans1;
  }
  i = 0; j = 0; ii = n - 1; jj = n - 1;
  while (i <= ii && j <= jj) {
    if (a[i] < b[j]) ++i, ++j, ++ans2;
    else ++i, --jj;
  }
  cout << ans1 << '\n' << ans2 << '\n';
  return 0;
}
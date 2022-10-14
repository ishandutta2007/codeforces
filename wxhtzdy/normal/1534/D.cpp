#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;
 
const int nax = 2005;
 
int n, a[nax][nax];
set<pair<int, int>> ans;
 
void Ask(int x) {
  cout << "? " << x + 1 << endl;
  for (int i = 0; i < n; i++) {
    cin >> a[x][i];
  }
}
 
void dodaj(int x) {
  for (int i = 0; i < n; i++) {
    if (a[x][i] == 1) {
      ans.insert({min(x, i), max(x, i)});
    }
  }
}
 
int main() {
  ios::sync_with_stdio(!cin.tie(0));
 
  cin >> n;
  if (n == 2) {
    cout << "!" << endl << 1 << " " << 2 << endl;
    return 0;
  }
  Ask(0);
  vector<int> x, y;
  for (int i = 1; i < n; i++) {
    if (a[0][i] % 2 == 0) {
      x.push_back(i);
    } else {
      y.push_back(i);
    }
  }
  if (x.size() < y.size()) {
    for (int i : x) Ask(i);
    for (int i : x) dodaj(i);
    dodaj(0);
  } else {
    for (int i : y) Ask(i);
    for (int i : y) dodaj(i);
  }
  cout << "!" << endl;
  for (auto &i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << endl;
  }
}
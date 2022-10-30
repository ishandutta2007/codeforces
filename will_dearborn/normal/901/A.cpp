#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi a(n+1);
  for (int i = 0; i < a.size(); ++i) cin >> a[i];
  int s = -1;
  for (int i = 0; i + 1 < a.size(); ++i) if (a[i] > 1 && a[i+1] > 1) {
    s = i; break;
  }
  if (s == -1) {
    cout << "perfect\n";
  } else {
    cout << "ambiguous\n";
    int sum = 0;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a[i]; ++j) {
        cout << sum << ' ';
      }
      sum += a[i];
    }
    cout << endl;
    sum = 0;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a[i]; ++j) {
        if (i == s + 1 && j == 0) {
          cout << sum - a[s] + 1 << ' ';
        } else {
          cout << sum << ' ';
        }
      }
      sum += a[i];
    }
    cout << endl;
  }
  return 0;
}
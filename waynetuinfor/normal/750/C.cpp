#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 5;
int n, c[maxn], d[maxn], rating, dv, ch, curHigh, curLow, Max, Min;
bool inf;

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> c[i] >> d[i];
  int high, low;
  dv = d[0]; ch = c[0];
  Max = INT_MAX; Min = INT_MIN;
  if (dv == 1) Min = 1900;
  else Max = 1899;
  inf = dv == 1;
  for (int i = 1; i < n; ++i) {
    if (d[i] == 2) inf = false;
    if (d[i] == 2) Max = min(Max, 1899 - ch);
    else Min = max(Min, 1900 - ch);
    if (dv == 1 && dv != d[i]) Max = min(Max, 1899 - ch);
    else if (dv == 2 && dv != d[i]) Min = max(Min, 1900 - ch);
    ch += c[i];
    dv = d[i];
  }
  if (inf) { cout << "Infinity\n"; return 0; }
  if (Max < Min) { cout << "Impossible\n"; return 0; }
  for (int i = 0; i < n; ++i) Max += c[i];
  cout << Max << '\n';
  return 0;
}
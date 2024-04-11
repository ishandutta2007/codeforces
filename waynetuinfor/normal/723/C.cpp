#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
using namespace std;

const int maxn = 2000 + 5;
int n, m, A[maxn], cnt[maxn], Min, chg;
bool add[maxn];
queue<int> q;
map<int, int> mp;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> A[i];
  int t = n / m;
  for (int i = 0; i < n; ++i) {
    if (A[i] < 1 || A[i] > m) { q.push(i); continue; }
    mp[A[i]]++;
    if (mp[A[i]] > t) q.push(i), mp[A[i]]--;
  }
  while (q.size()) {
    for (int i = 1; i <= m; ++i) {
      if (q.empty()) break;
      if (mp.find(i) == mp.end()) mp[i] = 0;
      while (mp[i] < t) {
        A[q.front()] = i;
        q.pop();
        mp[i]++;
        chg++;
      }
    }
    break;
  }
  while (q.size() >= m) {
    memset(add, false, sizeof(add));
    for (int i = 1; i <= m; ++i) {
      if (add[i]) continue;
      int a = q.front(); q.pop();
      if (A[a] >= 1 && A[a] <= m && !add[A[a]]) add[A[a]] = true, --i;
      else chg++, A[a] = i, add[i] = true;
    }
  }
  for (int i = 0; i < n; ++i) if (A[i] >= 1 && A[i] <= m) cnt[A[i]]++;
  Min = INT_MAX;
  for (int i = 1; i <= m; ++i) Min = min(Min, cnt[i]);
  cout << Min << ' ' << chg << '\n';
  for (int i = 0; i < n; ++i) cout << A[i] << ' ';
}
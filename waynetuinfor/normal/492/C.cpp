#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
struct Exam { int a, b; } ex[maxn];
int n, r;
long long avg, tot;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> r >> avg;
  for (int i = 0; i < n; ++i) cin >> ex[i].a >> ex[i].b, tot += ex[i].a;
  sort(ex, ex + n, [](const Exam& e1, const Exam& e2) {
    return e1.b < e2.b;
  });
  long long goal = avg * (long long)n - tot;
  long long ans = 0;
  for (int i = 0; i < n && goal > 0; ++i) {
    if (ex[i].a >= r) continue;
    long long div = min((long long)r - ex[i].a, goal);
    ans += (long long)ex[i].b * div;
    goal -= div;
  }
  cout << ans << '\n';
  return 0;
}
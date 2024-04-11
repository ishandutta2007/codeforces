//12C
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, m, p[105], cnt[105], t1, ans1, ans2, top;
string name, fruit[105];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> p[i];
  sort(p, p + n);
  top = 0;
  for (int i = 0; i < m; i++) {
    cin >> name;
    t1 = top;
    for (int j = 0; j < top; j++) {
      if (name == fruit[j]) {
        t1 = j;
        break;
      }
    }
    fruit[t1] = name;
    if (t1 == top) top++;
    cnt[t1]++;
  }
  sort(cnt, cnt + top);
  ans1 = 0; ans2 = 0;
  for (int i = 0; i < top; i++) {
    ans1 = ans1 + p[i] * cnt[top - i - 1];
  }
  for (int i = 0; i < top; i++) {
    ans2 = ans2 + p[n - i - 1] * cnt[top - i - 1];
  }
  cout << ans1 <<' ' << ans2 << endl;
  return 0;
}
#include <bits/stdc++.h>
std::vector<int> a;
int cnt[100001][2];
int main() {
  int n, T, flag;
  scanf("%d", &T);
  while(T--){
	scanf("%d", &n), a.resize(n), flag = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]), ++cnt[a[i]][i % 2];
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
      --cnt[a[i]][i % 2];
    for (int i = 0; i < n; ++i)
      if (cnt[a[i]][0] != 0 || cnt[a[i]][1] != 0) {
        puts("NO"), flag = 1;
		break;
      }
    if (flag == 0) puts("YES");
	a.clear();
	for (int i = 0; i < n; ++i)
      cnt[a[i]][0] = cnt[a[i]][1] = 0;
  }
  return 0;
}
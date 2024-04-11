#include <bits/stdc++.h>

using namespace std;

const string s = "Bulbasaur";

const int N = 1234567;

char foo[N];

int cnt[N];

int main() {
  scanf("%s", foo);
  for (int j = 0; j < 256; j++) {
    cnt[j] = 0;
  }
  for (int i = 0; foo[i]; i++) {
    cnt[foo[i]]++;
  }
  int ans = 0;
  while (true) {
    bool ok = true;
    for (int k = 0; k < (int) s.length(); k++) {
      if (cnt[s[k]] <= 0) {
        ok = false;
        break;
      }
      cnt[s[k]]--;
    }
    if (!ok) {
      break;
    }
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
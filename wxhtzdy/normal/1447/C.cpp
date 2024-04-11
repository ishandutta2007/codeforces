/**
 *  author: milos
 *  created: 08.10.2020 16:11:14
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> find_subset(long long l, long long u, vector<int> a) {
  int n = (int) a.size();
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  long long sum = v[0].first;
  int i = 0, j = 0;
  while (i < n && j < n) {
    if (sum >= l && sum <= u) {
      break;
    }
    if (sum <= u && j < n - 1) {
      if (j + 1 == n) {
        break;
      }
      j++;
      sum += v[j].first;
    } else {
      sum -= v[i].first;
      i++;
    }
  }
  vector<int> ans;
  if (sum >= l && sum <= u) {
    for (int h = i; h <= j; h++) {
      ans.push_back(v[h].second);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}
int main() {
    int tt;
    scanf("%i",&tt);
    while(tt--){
        int n;
        long long w;
        scanf("%i %lld",&n,&w);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%i",&a[i]);
        vector<int> ans = find_subset((w + 1) / 2, w, a);
        if ((int) ans.size() == 0) {
            cout << "-1" << "\n";
            continue;
        }
        cout << ans.size() << "\n";
        for (int c : ans) {
            cout << c + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
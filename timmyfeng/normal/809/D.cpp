#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<
  array<int, 2>,
  null_type,
  less<array<int, 2>>,
  rb_tree_tag,
  tree_order_statistics_node_update
>;

ordered_set lis;

int lower_bound(int x) {
  int lo = 0;
  int hi = lis.size();
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if ((*lis.find_by_order(mid))[0] + mid < x) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;

    if (lis.empty() || r > (*(--lis.end()))[0] + (int) lis.size() - 1) {
      lis.insert({2'000'000'000, i});
    }

    int ptr_l = lower_bound(l);
    int ptr_r = lower_bound(r);
    lis.erase(lis.find_by_order(ptr_r));
    lis.insert({l - ptr_l, i});
  }

  cout << lis.size() << "\n";
}
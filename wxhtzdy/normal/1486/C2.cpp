/**
 *    author:  milos
 *    created: 18.02.2021 20:23:20       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;  
  };
  int id = Ask(1, n);
  int l, r;
  if (id > 1 && Ask(1, id) == id) {
    int bot = 1, top = id - 1, ans = id;
    while (bot <= top) {
      //cout << bot << " " << top << '\n';
      int mid = (bot + top) / 2;
      int x = Ask(mid, id);
      if (x == id) {
        ans = mid;
        bot = mid + 1;
      } else {
        top = mid - 1;
      }
    }
    assert(ans != id);  
    cout << "! " << ans << endl;  
  } else {
    int bot = id + 1, top = n, ans = id;
    while (bot <= top) {
      int mid = (bot + top) / 2;
      int x = Ask(id, mid);
      if (x == id) {
        ans = bot;
        top = mid - 1;
      } else {
        bot = mid + 1;
      }
    }
    assert(ans != id); 
    cout << "! " << ans << endl;
  }
  return 0;
}
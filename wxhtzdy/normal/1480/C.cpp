/**
 *    author:  milos
 *    created: 07.02.2021 15:56:51       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "! 1" << endl;
    return 0;
  }
  auto Ask = [&](int i) {
    cout << "? " << i << endl;
    int x;
    cin >> x;
    return x;  
  };
  int a = Ask(1);
  int b = Ask(2);
  if (a < b) {
    cout << "! 1" << endl;
    return 0;
  }
  int aa = Ask(n);
  int bb = Ask(n - 1);
  if (aa < bb) {
    cout << "! " << n << endl;
    return 0;   
  }
  int bot = 2, top = n, ans = 2;
  while (bot <= top) {
    int mid = bot + top >> 1;
    int x = Ask(mid);
    int prv = Ask(mid - 1);
    if (x == n && x < prv) {
      cout << "! " << n << '\n';
      return 0;
    }
    int nxt = Ask(mid + 1);
    if (x < nxt && x < prv) {
      cout << "! " << mid << '\n';
      return 0;
    }
    if (x > nxt) {
      bot = mid + 1;  
    } else {
      top = mid - 1;
    }
  }
  if (ans == 2) {
    assert(false);
  }
  cout << ans << '\n';
  return 0;
}
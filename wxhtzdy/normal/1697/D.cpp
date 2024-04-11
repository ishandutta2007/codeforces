/**
 *    author:  wxhtzdy
 *    created: 13.06.2022 16:09:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  auto Ask1 = [&](int i) {
    cout << "? 1 " << i << endl;
    char x;
    cin >> x;
    return x;
  };
  auto Ask2 = [&](int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
  };
  string ans = "";
  vector<int> pos(26, -1);           
  for (int i = 1; i <= n; ) {
    int ptr = i + 1;
    while (ptr <= n && Ask2(i, ptr) == 1) {
      ptr += 1;
    }
    vector<int> b;
    for (int j = 0; j < 26; j++) {
      if (pos[j] != -1) {
        b.push_back(pos[j]);
      }
    }   
    sort(b.rbegin(), b.rend());
    int low = 0, high = b.size() - 1, at = -1;
    while (low <= high) {
      int mid = low + high >> 1;
      if (Ask2(b[mid], i) == mid + 1) {
        at = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    char ch;
    if (at == -1) {
      ch = Ask1(i);
    } else {
      ch = ans[b[at] - 1];  
    }
    pos[ch - 'a'] = i;
    for (int j = 0; j < ptr - i; j++) {
      ans += ch;
    }
    i = ptr;
  }
  cout << "! " << ans << endl;
  return 0;
}
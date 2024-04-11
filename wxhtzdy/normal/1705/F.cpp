/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 21:15:56
**/
#include <bits/stdc++.h>

using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  auto Ask = [&](string s) {
    cout << s << endl;
    int x;
    cin >> x;
    if (x == n) {
      exit(0);
    }
    return x;
  };
  string s0 = string(n, 'T');
  string s1 = "";
  for (int i = 0; i < n; i++) {
    s1 += (i % 2 == 0 ? 'T' : 'F');
  }
  int c0 = Ask(s0);
  int c1 = Ask(s1);
  string ans = string(n, '#');
  int l = 0, r = n - 1;
  while (l <= r) {
    if (l == r) {
      s0[l] = (s0[l] ^ 'F' ^ 'T');
      if (Ask(s0) > c0) {
        ans[l] = 'F';
      } else {
        ans[l] = 'T';
      }
      break;
    }
    s1[l] = (s1[l] ^ 'F' ^ 'T');
    s1[l + 1] = (s1[l + 1] ^ 'F' ^ 'T');
    int d = Ask(s1);
    if (d == c1 + 2) {
      ans[l] = s1[l];
      ans[l + 1] = s1[l + 1];
      s1[l] = (s1[l] ^ 'F' ^ 'T');
      s1[l + 1] = (s1[l + 1] ^ 'F' ^ 'T');
      l += 2;
      continue;
    }
    if (d == c1 - 2) {
      ans[l] = (s1[l] ^ 'F' ^ 'T');
      ans[l + 1] = (s1[l + 1] ^ 'F' ^ 'T');
      s1[l] = (s1[l] ^ 'F' ^ 'T');
      s1[l + 1] = (s1[l + 1] ^ 'F' ^ 'T');
      l += 2;
      continue;
    }       
    if (l + 1 == r) {
      s0[l] = (s0[l] ^ 'F' ^ 'T');
      if (Ask(s0) > c0) {
        ans[l] = 'F';
      } else {
        ans[l] = 'T';
      }
      ans[l + 1] = ans[l];
      l += 2;
      continue;
    }
    s1[l] = (s1[l] ^ 'F' ^ 'T');
    s1[l + 1] = (s1[l + 1] ^ 'F' ^ 'T');
    s0[l] = 'F';
    s0[l + 1] = 'F';
    s0[r] = 'F';
    d = Ask(s0);
    if (d == c0 - 3) {
      ans[l] = 'T';
      ans[l + 1] = 'T';
      ans[r] = 'T';
    }
    if (d == c0 + 3) {
      ans[l] = 'F';
      ans[l + 1] = 'F';
      ans[r] = 'F';
    }
    if (d == c0 - 1) {
      ans[l] = 'T';
      ans[l + 1] = 'T';
      ans[r] = 'F';
    }
    if (d == c0 + 1) {
      ans[l] = 'F';
      ans[l + 1] = 'F';
      ans[r] = 'T';
    }
    s0[l] = 'T';
    s0[l + 1] = 'T';
    s0[r] = 'T';
    l += 2;
    r -= 1;
  }   
  Ask(ans);
  return 0;
}
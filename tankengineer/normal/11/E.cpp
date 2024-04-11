//CF 11E
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int l, ans;
string s;
char t[1000005];

int cal(string s) {
  int l = s.size(), p = 0, q = 0, cnt1 = 0, flag = 0;
  char ch;
  for (int i = 0; i < l; i++) {
    ch = (q & 1) ? 'R' : 'L';
    if (s[i] == 'X') {
      q++;
    } else {
      if (s[i] == ch) {
        p++;
        q++;
        flag = 0;
      } else {
        p++;
        q += 2;
        cnt1 += flag;
        flag = !flag;
      }
    }
  }
  if (q & 1) {
    q++;
    cnt1 += flag;
  }
  if (p * 2 > q) {
    p -= cnt1;
    q -= cnt1 * 2;
  }
  return (long long)p * 100000000 / q;
}

int main() {
  s = "";
  scanf("%s", &t);
  l = strlen(t);
  for (int i = 0; i < l; i++) {
    if (i > 0 && t[i] == t[i - 1] && t[i] != 'X') {
      s += 'X';
    }
    s += t[i];
  }
  if (s[0] == s[s.size() - 1] && s[0] != 'X') {
    ans = max(cal(s + 'X'), cal('X' + s));
  } else {
    ans = cal(s);
  }
  printf("%d.%.06d\n", ans / 1000000, ans % 1000000);
  return 0;
}
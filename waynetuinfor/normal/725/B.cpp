#include <iostream>
#include <string>
using namespace std;

string s;
long long n;
long long m, cnt;

int main() {
  cin >> s;
  n = 0;
  for (int i = 0; i < s.length() - 1; ++i) {
    n = n * 10 + s[i] - '0';
  }
  m = n % 4;
  // n *= 10;
  // if (s[s.length() - 1] == 'f') n += 1;
  // if (s[s.length() - 1] == 'e') n += 2;
  // if (s[s.length() - 1] == 'd') n += 3;
  // if (s[s.length() - 1] == 'c') n += 6;
  // if (s[s.length() - 1] == 'b') n += 5;
  // if (s[s.length() - 1] == 'a') n += 4;
  // cout << n << endl;
  cnt = 0;
  if (m == 1 || m == 2) {
    cnt += n - 1;
    // int i = 1;
    // while ()
    // if (n % 2 == 1) {
    //   cnt += 6 *
    // }
    cnt += 6 * ((n - 1) / 2);
    if (n % 2 == 0) cnt += 6;
    if (s[s.length() - 1] == 'f') cnt += 1;
    if (s[s.length() - 1] == 'e') cnt += 2;
    if (s[s.length() - 1] == 'd') cnt += 3;
    if (s[s.length() - 1] == 'c') cnt += 6;
    if (s[s.length() - 1] == 'b') cnt += 5;
    if (s[s.length() - 1] == 'a') cnt += 4;
  } else {
    cnt += n - 3;
    int i = 1;
    // while ()
    // if (n % 2 == 1) {
    //   cnt += 6 *
    // }
    cnt += 6 * ((n - 3) / 2);
    if (n % 2 == 0) cnt += 6;
    if (s[s.length() - 1] == 'f') cnt += 1;
    if (s[s.length() - 1] == 'e') cnt += 2;
    if (s[s.length() - 1] == 'd') cnt += 3;
    if (s[s.length() - 1] == 'c') cnt += 6;
    if (s[s.length() - 1] == 'b') cnt += 5;
    if (s[s.length() - 1] == 'a') cnt += 4;
  }
  cout << cnt << endl;
  return 0;
}
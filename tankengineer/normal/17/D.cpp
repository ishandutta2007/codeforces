//17D
#include<iostream>
#include<string>

using namespace std;

long long c, b_mod, ten_mod, b_ten_mod, ans, t1;
string b, n;

int main() {
  cin >> b >> n >> c;
  b_mod = 0; ten_mod = 1;
  for (int i = b.size() - 1; i >= 0; i--) {
    b_mod = (b_mod + ((b[i] - '0') * ten_mod) % c) % c;
    ten_mod = (ten_mod * 10) % c;
  }
  ans = 1;
  b_ten_mod = b_mod;
  for (int i = n.size() - 1; n[i]-- == '0'; i--) n[i] = '9';
  for (int i = n.size() - 1; i >= 0; i--) {
    for (int j = 1; j <= n[i] - '0'; j++) {
      ans = (ans * b_ten_mod) % c;
    }
    t1 = b_ten_mod;
    for (int j = 0; j < 9; j++) {
      b_ten_mod = (b_ten_mod * t1) % c;
    }
  }
  b_mod--;
  if (b_mod < 0) b_mod += c;
  ans = (ans * b_mod) % c;
  if (ans == 0) {
    cout << c << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
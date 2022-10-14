#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, x;
  cin >> a >> b >> x;
  if (x % 2 == 0) {
    if (a > b) {
      for (int i = 0; i < x / 2; i++) {
        cout << 0;
        cout << 1;
      }
      for (int i = 0; i < b - x / 2; i++) {
        cout << 1;
      }
      for (int i = 0; i < a - x / 2; i++) {
        cout << 0;
      }
    } else {
      for (int i = 0; i < x / 2; i++) {
        cout << 1;
        cout << 0;
      }
      for (int i = 0; i < a - x / 2; i++) {
        cout << 0;
      }
      for (int i = 0; i < b - x / 2; i++) {
        cout << 1;
      }
    }
  } else {
    if (a > b) {
      for (int i = 0; i < x / 2; i++) {
        cout << 0;
        cout << 1;
      }
      for (int i = 0; i < a - x / 2; i++) {
        cout << 0;
      }
      for (int i = 0; i < b - x / 2; i++) {
        cout << 1;
      }
    } else {
      for (int i = 0; i < x / 2; i++) {
        cout << 1;
        cout << 0;
      }
      for (int i = 0; i < b - x / 2; i++) {
        cout << 1;
      }
      for (int i = 0; i < a - x / 2; i++) {
        cout << 0;
      }
    }
  }
  return 0;
}
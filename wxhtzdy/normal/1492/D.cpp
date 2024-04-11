/**
 *    author:  milos
 *    created: 23.02.2021 10:35:04       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, k;
  cin >> b >> a >> k;
  int n = a + b;
  if (b == 0 && k > 0) {
    cout << "No" << '\n';
    return 0;
  }
  if (a == 1 && k > 0) {
    cout << "No" << '\n';
    return 0;  
  }
  /*if (k > b && k < a - 1) {
    cout << "No" << '\n';
    return 0;  
  }*/
  if (a > 1) {
    if (k <= b) {
      int diff = b - k;  
      cout << "Yes" << '\n';
      for (int i = 0; i < a; i++) {
        cout << '1';
      }
      for (int i = 0; i < b; i++) {
        cout << '0';
      }
      cout << '\n';
      for (int i = 0; i < a - 1; i++) {
        cout << '1';
      }
      for (int i = 0; i < k; i++) {
        cout << '0';
      }
      cout << '1';
      for (int i = 0; i < diff; i++) {
        cout << '0';
      }
      return 0;
    }
    if (k < a - 1) {
      cout << "Yes" << '\n';
      for (int i = 0; i < a; i++) {
        cout << 1;  
      }
      for (int i = 0; i < b; i++) {
        cout << 0;
      }
      cout << '\n';
      for (int i = 0; i < a - k; i++) {
        cout << 1;  
      }
      for (int i = 0; i < b; i++) {
        cout << 0;
      }
      for (int i = 0; i < k; i++) {
        cout << 1;
      }
      return 0;
    }
    if (a >= 2) {
      if (k > a + b - 2) {
        cout << "No" << '\n';
        return 0;
      }
      /*if (b < k - a + 2) {
        cout << "
      }*/
      int st = a + b - 2 - k;
      cout << "Yes" << '\n';
      for (int i = 0; i < a; i++) {
        cout << 1;
      }
      for (int i = 0; i < b; i++) {
        cout << 0;
      }   
      cout << '\n';     
      cout << 1;
      if (b > 0) {
        cout << 0;
      }
      for (int i = 0; i < a - 2; i++) {
        cout << 1;
      }
      for (int i = 0; i < min(b - 1, k - a + 1); i++) {
        cout << 0;
      }
      if (a > 1) {
        cout << 1;
      }
      for (int i = 0; i < b - k + a - 2; i++) {
        cout << 0;
      }
      return 0;
    }
    cout << "No" << '\n';
    return 0;
  }
  if (k != 0) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  cout << 1;
  for (int i = 0; i < b; i++) {
    cout << 0;
  }
  cout << '\n';
  cout << 1;
  for (int i = 0; i < b; i++) {
    cout << 0;
  }    
  return 0;
}
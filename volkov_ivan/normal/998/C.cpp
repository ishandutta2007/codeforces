#include <iostream>
 
 using namespace std;
 
 int main() {
     long long n, x, y, k = 0, cnt = 0;
     cin >> n >> x >> y;
     string s;
     cin >> s;
     for (int i = 0; i < n; i++) {
         if (s[i] == '0') cnt++;
         else {
             if (cnt != 0) k++;
             cnt = 0;
         }
     }
    if (cnt != 0) k++;
     if (k == 0) {
         cout << 0 << endl;
         return 0;
     }
     if (y < x) {
         cout << y * k << endl;
     } else {
         cout << x * (k - 1) + y << endl;
     }
     return 0;
 }
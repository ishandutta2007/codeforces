#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
    cin >> a[i];   
   }
   cout << (a[0] < a[n - 1] ? "YES" : "NO") << endl;
  }
}
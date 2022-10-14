#include <bits/stdc++.h>

using namespace std;
          
bool ok(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;    
    n /= 10;
  }
  return sum == 10;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a; 
  int nxt = 1;
  while ((int) a.size() < 10000) {
    if (ok(nxt)) a.push_back(nxt);
    nxt++;  
  }
  int k;
  cin >> k;
  cout << a[k - 1] << '\n';
  return 0;
}
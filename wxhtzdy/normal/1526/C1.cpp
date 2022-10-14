#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;
 
int main() {
  ios::sync_with_stdio(!cin.tie(0));
 
  int n;
  cin >> n;
 
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  priority_queue<int> pq;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    pq.push(-a[i]);
 
    while (sum < 0) {
      sum += pq.top();
      pq.pop();
    }
  }
 
  cout << pq.size() << '\n';
}
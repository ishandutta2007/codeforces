#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
  cin >> n;
  int j = n;
  for (int i = n; i >= 1; --i) {
    int a; cin >> a;
    pq.push(a);
    while (pq.size() && pq.top() == j) {
      cout << pq.top() << ' ';
      pq.pop();
      --j;
    }
    cout << '\n';
  }
  return 0;
}
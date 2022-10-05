#include <bits/stdc++.h>
using namespace std;
void print_v(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    v[0] = 2;
    for (int i = 1; i < n; i++) {
      v[i] = v[i - 1] + 1;
    }
    print_v(v);
  }
}
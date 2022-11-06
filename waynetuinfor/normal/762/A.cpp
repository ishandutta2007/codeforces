#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> div1, div2;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0 && i == n / i) div1.push_back(i);
    else if (n % i == 0) div1.push_back(i), div2.push_back(n / i);
  }
  if (k <= div1.size()) cout << div1[k - 1] << '\n';
  else if (k <= div2.size() + div1.size()) cout << div2[div2.size() - (k - div1.size())] << '\n';
  else cout << "-1\n";
  return 0;
}
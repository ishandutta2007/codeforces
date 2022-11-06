#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, ans;
long long k;

int main() {
  cin >> n >> k;
  ans = 1;
  while (k % 2 == 0) k /= 2, ans++;
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

long long length[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> length[i];
  }

  string s;
  cin >> s;

  long long ans = 0;
  long long one = 0;
  long long two = 0;
  long long used;
  int coeff = 5;

  for (int i = 0; i < n; ++i) {
    switch (s[i]) {
      case 'G':
        used = min(one, length[i]);
        ans += 3 * length[i] - used;
        two += length[i] + used;
        one -= used;
        break;
      case 'W':
        ans += 2 * length[i];
        one += length[i];
        coeff = 3;
        break;
      default:
        ans += length[i];

        used = min(one, length[i]);
        length[i] -= used;
        ans += used;
        one -= used;

        used = min(two, length[i]);
        length[i] -= used;
        ans += 2 * used;
        two -= used;

        ans += coeff * length[i];
    }
  }

  cout << ans << "\n";
}
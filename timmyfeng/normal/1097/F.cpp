#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 1;
const int A = 7'000 + 1;

bitset<A> number_set[N];
bitset<A> mobius_mask[A];
int mu[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(mu + 1, mu + A, 1);
  for (int i = 2; i * i < A; ++i) {
    for (int j = i * i; j < A; j += i * i) {
      mu[j] = 0;
    }
  }

  for (int i = 1; i < A; ++i) {
    for (int j = 1; i * j < A; ++j) {
      mobius_mask[i][i * j] = mu[j];
    }
  }

  int n, q;
  cin >> n >> q;

  while (q--) {
    int type, x, y, z, v;
    cin >> type;
    switch (type) {
      case 1:
        cin >> x >> v;
        number_set[x].reset();
        for (int i = 1; i * i <= v; ++i) {
          if (v % i == 0) {
            number_set[x][i] = 1;
            if (i * i != v) {
              number_set[x][v / i] = 1;
            }
          }
        }
        break;
      case 2:
        cin >> x >> y >> z;
        number_set[x] = number_set[y] ^ number_set[z];
        break;
      case 3:
        cin >> x >> y >> z;
        number_set[x] = number_set[y] & number_set[z];
        break;
      default:
        cin >> x >> v;
        cout << (number_set[x] & mobius_mask[v]).count() % 2;
    }
  }
  cout << "\n";
}
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 3e5 + 10;
const int B = 300;

pair<ll, int> t[N];
void update(int v) {
  for (int u = v; u < N; u += u & (-u)) {
    t[u].F += v;
    t[u].S++;
  }
}

pair<ll, int> get(int v) {
  pair<ll, int> result = {0, 0};
  for (; v > 0; v -= v & (-v)) {
    result.F += t[v].F;
    result.S += t[v].S;
  }
  return result;
}

pair<ll, int> get_sum(int l, int r) {
  auto A = get(r), B = get(l - 1);
  return {A.F - B.F, A.S - B.S};
}

int ad[B + 1], was[B + 1];
 
const int MX = 3e5;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  ll answer = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    if (x <= B) {
      answer += ad[x];
    } else {
      auto kek = get_sum(x + 1, MX);
      answer += kek.S * 1ll * x;
      auto kek2 = get_sum(1, x - 1);
      answer += kek2.F;
      for (int j = 1; x * j <= 3e5; j++) {
        auto kek = get_sum(x * j, min(MX, x * (j + 1) - 1));
        answer += kek.F - x * 1ll * kek.S * j;        
      }

      int prv = x - 1;
      for (int j = 1;; j++) {
        if (prv <= B) {
          break;
        }
        int new_prv = x / (j + 1);
        auto kek = get_sum(new_prv + 1, prv);
        answer += x * 1ll * kek.S - kek.F * j;
        prv = new_prv;
      }

      for (int j = 1; j <= prv; j++) {
        if (was[j]) {
          answer += x % j;
        }
      }
    }

    if (x <= B) {
      was[x] = true;
    }

    update(x);

    for (int i = 1; i <= B; i++) {
      ad[i] += x % i + i % x;
    }

    cout << answer << ' ';
  }
  cout << '\n';
}
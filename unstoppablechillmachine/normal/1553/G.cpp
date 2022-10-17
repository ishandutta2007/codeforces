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
 
const int MX = 1e6 + 10;
const int N = 2e5 + 10;
int del[MX], a[N];
vector<int> factorization[N];

int p[MX], sz[MX];

int find(int v) {
  return p[v] == v ? v : p[v] = find(p[v]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) {
    return;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  sz[a] += sz[b];
  p[b] = a;
  return;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

  for (int i = 1; i < MX; i++) {
    p[i] = i;
    sz[i] = 1;
  }

  for (int i = 2; i < MX; i++) {
    if (!del[i]) {
      del[i] = i;
      if (i * 1ll * i < MX) {
        for (int j = i * i; j < MX; j += i) {
          del[j] = i;
        }
      }
    }
  }

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int cur = a[i];
    while (cur > 1) {
      int p = del[cur];
      while (cur % p == 0) {
        cur /= p;
      }
      if (!factorization[i].empty()) {
        merge(factorization[i].back(), p);
      }
      factorization[i].pb(p);
    }  
  }
  map<pair<int, int>, vector<int>> que;
  vector<int> answer(q);
  for (int i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;
    answer[i] = 2;
    if (find(factorization[s].back()) == find(factorization[t].back())) {
      answer[i] = 0;
    } else {
      que[{find(factorization[s].back()), find(factorization[t].back())}].pb(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    vector<int> kek = factorization[i];
    int cur = a[i] + 1;
    while (cur > 1) {
      int p = del[cur];
      while (cur % p == 0) {
        cur /= p;
      }
      kek.pb(p);
    }
    for (int j : kek) {
      for (int k : kek) {
        pair<int, int> rofl = {find(j), find(k)};
        for (auto it : que[rofl]) {
          answer[it] = 1;
        }
        que[rofl] = {};
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cout << answer[i] << '\n';
  }
}
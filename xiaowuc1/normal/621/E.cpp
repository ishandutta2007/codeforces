#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int n, b, k, x;
const int MOD = 1000000007;

matrix mult(matrix& a, matrix& b) {
  matrix c;
  c.resize(x);
  for(int i = 0; i < c.size(); i++) {
    c[i].resize(x);
    for(int j = 0; j < c[i].size(); j++) {
      for(int k = 0; k < b.size(); k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= MOD;
      }
    }
  }
  return c;
}

matrix exp(matrix b, int e) {
  matrix r;
  r.resize(x);
  for(int i = 0; i < x; i++) {
    r[i].resize(x);
    r[i][i] = 1;
  }
  while(e) {
    if(e%2) {
      r = mult(r, b);
    }
    e /= 2;
    if(e) {
      b = mult(b, b);
    }
  }
  return r;
}

int freq[10];
void solve() {
  cin >> n >> b >> k >> x;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    freq[t]++;
  }
  matrix trans;
  trans.resize(x);
  for(int i = 0; i < trans.size(); i++) {
    trans[i].resize(x);
  }
  for(int i = 0; i < x; i++) {
    for(int j = 1; j <= 9; j++) {
      trans[i][(10*i+j)%x] += freq[j];
    }
  }
  trans = exp(trans, b);
  cout << trans[0][k] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
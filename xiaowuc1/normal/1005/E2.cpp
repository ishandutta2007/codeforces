#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_BIT_SIZE = 600000;
const int BIT_INC = 300000;

int n, want;
int l[BIT_INC];
int bit[2][MAX_BIT_SIZE];

void bit_update(int r, int c, int v) {
  c += BIT_INC;
  while(c < MAX_BIT_SIZE) {
    bit[r][c] += v;
    c += c & -c;
  }
}
int bit_query(int r, int c) {
  int ret = 0;
  c += BIT_INC;
  while(c) {
    ret += bit[r][c];
    c -= c & -c;
  }
  return ret;
}

ll solve(int thresh) {
  // return num of intervals where median <= thresh
  memset(bit, 0, sizeof(bit));
  int curr = 0;
  ll ret = 0;
  bit_update(0, 0, 1);
  for(int i = 1; i <= n; i++) {
    if(l[i] > thresh) {
      curr--;
    }
    else {
      curr++;
    }
    ret += bit_query(i%2, curr);
    ret += bit_query(1^(i%2), curr);
    bit_update(i%2, curr, 1);
  }
  return ret;
}

void solve() {
  cin >> n >> want;
  for(int i = 1; i <= n; i++) cin >> l[i];
  // slowsolve(want);
  // slowsolve(want+1);
  cout << solve(want) - solve(want-1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}
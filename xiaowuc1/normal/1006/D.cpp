#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
string a, b;

void solve() {
  cin >> n >> a >> b;
  int ret = 0;
  int lhs = 0;
  int rhs = n-1;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      if(a[lhs] != b[lhs]) {
        ret++;
      }
    }
    else {
      if(a[lhs] == b[lhs] && a[rhs] == b[rhs]) {}
      else if(a[lhs] == b[rhs] && a[rhs] == b[lhs]) {}
      else if(a[lhs] == a[rhs] && b[lhs] == b[rhs]) {}
      else if(b[lhs] == b[rhs]) ret++;
      else if(a[lhs] == b[lhs]) ret++;
      else if(a[lhs] == b[rhs]) ret++;
      else if(a[rhs] == b[lhs]) ret++;
      else if(a[rhs] == b[rhs]) ret++;
      else ret += 2;
    }
    lhs++; rhs--;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
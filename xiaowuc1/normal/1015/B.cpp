#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char s[55];
char t[55];

void die() {
  cout << "-1\n";
  exit(0);
}

void solve() {
  int n;
  scanf("%d\n%s%s", &n, s, t);
  vector<int> ret;
  for(int i = 0; i < n; i++) {
    if(s[i] == t[i]) continue;
    int j = i;
    while(j < n && s[j] != t[i]) j++;
    if(j == n) die();
    while(j != i) {
      ret.push_back(j);
      swap(s[j-1], s[j]);
      j--;
    }
  }
  cout << ret.size() << endl;
  for(int out: ret) cout << out << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}
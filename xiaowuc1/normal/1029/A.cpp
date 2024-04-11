#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for(int suffix = 1; true; suffix++) {
    string curr = "";
    curr += s;
    for(int a = 0; a < k-1; a++) {
      curr += s.substr(s.size()-suffix);
    }
    int amt = 0;
    for(int i = 0; i <= curr.size() - s.size(); i++) {
      if(curr.substr(i, s.size()) == s) amt++;
    }
    if(amt == k) {
      cout << curr << endl;
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}
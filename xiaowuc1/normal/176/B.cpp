#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool good(string& start, string& end, int off) {
  for(int i = 0; i < start.size(); i++) {
    int j = (i+off)%end.size();
    if(start[i] != end[j]) return false;
  }
  return true;
}

void solve() {
  string start, end;
  cin >> start >> end;
  int match = 0;
  int notmatch = 0;
  for(int i = 0; i < start.size(); i++) {
    (good(start, end, i) ? match : notmatch)++;
  }
  int a;
  cin >> a;
  ll startMatch = 0;
  ll endMatch = 0;
  if(good(start, end, 0)) startMatch++;
  else endMatch++;
  int MOD = 1000000007;
  while(a--) {
    ll nextStartMatch = 0;
    nextStartMatch += startMatch * (match - 1);
    nextStartMatch += endMatch * match;
    ll nextEndMatch = 0;
    nextEndMatch += startMatch * notmatch;
    nextEndMatch += endMatch * (notmatch - 1);
    startMatch = nextStartMatch % MOD;
    endMatch = nextEndMatch % MOD;
  }
  cout << startMatch << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}
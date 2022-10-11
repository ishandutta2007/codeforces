#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
int beforeDP[203][102];
int afterDP[102];

int match[203];
int nomatch[203];
string s;

int nbeforeDP[203][102];
int nafterDP[102];
int n;

void iterate() {
  memset(nbeforeDP, 0, sizeof(nbeforeDP));
  memset(nafterDP, 0, sizeof(nafterDP));
  for(int d = 0; d <= n; d++) {
    nafterDP[d+1] += afterDP[d];
    if(nafterDP[d+1] >= MOD) nafterDP[d+1] -= MOD;
    if(d) {
      nafterDP[d-1] += afterDP[d];
      if(nafterDP[d-1] >= MOD) nafterDP[d-1] -= MOD;
    }
    for(int i = 0; i < s.size(); i++) {
      int nd = d + (s[i] == '(' ? 1 : -1);
      if(nd < 0) continue;
      if(i+1 == s.size()) {
        nafterDP[nd] += beforeDP[i][d];
        if(nafterDP[nd] >= MOD) nafterDP[nd] -= MOD;
      }
      else {
        nbeforeDP[i+1][nd] += beforeDP[i][d];
        if(nbeforeDP[i+1][nd] >= MOD) nbeforeDP[i+1][nd] -= MOD;
      }
    }
    for(int i = 0; i < s.size(); i++) {
      int nd = d + (s[i] == '(' ? -1 : 1);
      if(nd < 0) continue;
      nbeforeDP[nomatch[i]][nd] += beforeDP[i][d];
      if(nbeforeDP[nomatch[i]][nd] >= MOD) nbeforeDP[nomatch[i]][nd] -= MOD;
    }
  }
  memcpy(beforeDP, nbeforeDP, sizeof(beforeDP));
  memcpy(afterDP, nafterDP, sizeof(afterDP));

}

void precomp() {
  for(int a = 0; a < s.size(); a++) {
    match[a] = a+1;
    string cand = s.substr(0, a);
    if(s[a] == '(') cand += ")";
    else cand += "(";
    while(cand.size() && s.find(cand) != 0) {
      cand = cand.substr(1, cand.size()-1);
    }
    nomatch[a] = cand.size();
  }
}

void solve() {
  cin >> n >> s;
  precomp();
  beforeDP[0][0]++;
  for(int qq = 0; qq < 2*n; qq++) {
    iterate();
  }
  cout << afterDP[0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=(n), i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

void init_io() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}

int solve(const string &text) {
  if (text.size() == 1 || text[1] >= text[0]) return 1;

  int pos = 1;
  while (pos < int(text.size()) && text[pos] <= text[pos-1]) ++pos;
  return pos;
}

string solve_one() {
  int len;
  cin >> len;
  string text;
  cin >> text;
  int pos = solve(text);
  string res = text.substr(0, pos);
  reverse(text.begin(), text.begin() + pos);
  res += text.substr(0, pos);
  return res;
}

int main() {
  init_io();

  int ntc; cin >> ntc;
  REP(tc, ntc) {
    auto x = solve_one();
    cout << x << "\n";
  }
}
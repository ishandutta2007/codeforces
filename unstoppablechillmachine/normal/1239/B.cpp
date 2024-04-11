#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
bool check(string s) {
	int balance = 0;
	for (int i = 0; i < SZ(s); i++) {
		if (s[i] == '(') {
			balance++;
		}
		else {
			balance--;
		}
		if (balance < 0) {
			return false;
		}
	}
	return (balance == 0);
}

vector<int> have[3];

inline int get(int vl, int l, int r) {
	return upper_bound(all(have[vl]), r) - lower_bound(all(have[vl]), l);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  pair<int, int> mn_bal = {0, 0};
  int sum = 0;
  for (int i = 0; i < n; i++) {
  	if (s[i] == '(') {
  		sum++;
  	}
  	else {
  		sum--;
  	}
  	mn_bal = min(mn_bal, make_pair(sum, i));
  }
  if (sum != 0) {
  	cout << 0 << '\n';
  	cout << 1 << ' ' << 1 << '\n';
  	exit(0);
  }
  int shift = 0;
  if (mn_bal.F < 0) {
  	shift = mn_bal.S + 1;
  	string s2;
  	for (int i = mn_bal.S + 1; i < n; i++) {
  		s2.pb(s[i]);
  	}
  	for (int i = 0; i <= mn_bal.S; i++) {
  		s2.pb(s[i]);
  	}
  	s = s2;
  }
  assert(check(s));

  vector<pair<int, int>> blocks;
  int balance = 0;
  for (int i = 0; i < SZ(s); i++) {
  	if (s[i] == '(') {
  		balance++;
  	}
  	else {
  		balance--;
  	}
  	if (balance <3) {
  		have[balance].pb(i);
  	}
  }
  pair<int, pair<int, int>> ans = make_pair(SZ(have[0]), make_pair(1, 1));
  int prv = 0;
  for (int i = 0; i < SZ(have[0]); i++) {
  	int p1 = prv + 1 + shift, p2 = have[0][i] + 1 + shift;
  	if (p1 > n) {
  		p1 -= n;
  	}
  	if (p2 > n) {
  		p2 -= n;
  	}
  	ans = max(ans, make_pair(get(1, prv, have[0][i]), make_pair(p1, p2)));
  	prv = have[0][i] + 1;
  }

  for (int i = 0; i + 1 < SZ(have[1]); i++) {
  	if (get(0, have[1][i], have[1][i + 1]) != 0) {
  		continue;
  	}
  	int p1 = have[1][i] + 2 + shift, p2 = have[1][i + 1] + 1 + shift;
  	if (p1 > n) {
  		p1 -= n;
  	}
  	if (p2 > n) {
  		p2 -= n;
  	}
  	ans = max(ans, make_pair(SZ(have[0]) + get(2, have[1][i], have[1][i + 1]), make_pair(p1, p2)));
  }

  cout << ans.F << '\n' << ans.S.F << ' ' << ans.S.S << '\n';
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

int f(string x) {
	int c = 0;
	for (auto it : x) {
		if (it == '1') {
			c++;
		}
	}
	return c;
}

bool sub(string &a, string b) {
	for (int i = 0; i < 7; i++) {
		if (a[i] == '1' && b[i] == '0') {
			return false;
		}
	}
	return true;
}

const int N = 2010;
int l[N], r[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> s = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  int ptr = 0;
  for (auto &it : a) {
  	cin >> it;
  	int mn = 10, mx = -1;
  	for (int i = 0; i < 10; i++) {
  		if (sub(it, s[i])) {
  			mn = min(mn, f(s[i]) - f(it));
  			mx = max(mx, f(s[i]) - f(it));
  		}
  	}
  	if (mn == 10) {
  		cout << -1 << '\n';
  		exit(0);
  	}
  	ptr++;
  	l[ptr] = mn;
  	r[ptr] = mx;
  }
  for (int i = n - 1; i >= 1; i--) {
  	l[i] += l[i + 1];
  	r[i] += r[i + 1];
  }
  vector<int> rez;
  for (int i = 1; i <= n; i++) {
  	int take = -1;
  	for (int j = 9; j >= 0; j--) {
  		if (sub(a[i - 1], s[j]) && k - (f(s[j]) - f(a[i - 1])) >= l[i + 1] && k - (f(s[j]) - f(a[i - 1])) <= r[i + 1]) {
  			take = j;
  			break;
  		} 
  	}
  	if (take == -1) {
  		cout << -1 << '\n';
  		exit(0);
  	}
  	rez.pb(take);
  	k -= f(s[take]) - f(a[i - 1]);
  }   
  for (auto it : rez) {
  	cout << it;
  }
}
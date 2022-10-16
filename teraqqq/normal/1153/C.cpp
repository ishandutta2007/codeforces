#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;

const int INF = 1e9;
const ll LINF = 1e18;

const int N = 3e5+7;

char s[N];
int n, a, b, ok = 1, h, x;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		a += (s[i] == '(') - (s[i] == ')');
		b += s[i] == '?';
	}

	if((a+b)%2 != 0) ok = 0;
	x = (b-a)/2;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '?') s[i] = x ? (--x, '(') : ')';
		h += (s[i] == '(') - (s[i] == ')');
		if(h <= 0 && i != n-1) ok = 0;
	}

	if(ok && h == 0) cout << s << endl;
	else cout << ":(" << endl;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n, l, r;
char a[N], b[N];
void m() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	bool ok = 0;
	for(int i = 1; i <= n; ++ i) {
		ok ^= (a[i] ^ b[i]);
	}
	if(ok && (n - 1) % 2 == 0) {
		puts("-1");
		return;
	}
	if((n - 1) % 2 == 0) {
		vector <int> L, R;
		for(int i = 1; i <= n; ++ i) if(a[i] ^ b[i]) {
			if(a[i] == '0') L.push_back(i);
			else R.push_back(i);
		}
		if((L.size() + R.size()) & 1) {
			puts("-1");
			return;
		}
		int ans = 1e9;
		swap(L, R);
		if(L.size() >= R.size() && L.size() <= R.size() + 1) ans = min(ans, (int)L.size() + (int)R.size());
		L.clear(); R.clear();
		for(int i = 1; i <= n; ++ i) if(a[i] == b[i]) {
			if(a[i] == '0') L.push_back(i);
			else R.push_back(i);
		}
		swap(L, R);
		if(L.size() >= R.size() && L.size() <= R.size() + 1) ans = min(ans, (int)L.size() + (int)R.size());
		if(ans > n) {
			puts("-1");
		} else cout << ans << endl;
	} else {
		vector <int> L, R;
		if(ok) {
			for(int i = 1; i <= n; ++ i) if(a[i] == b[i]) {
				if(a[i] == '0') L.push_back(i);
				else R.push_back(i);
			}
		} else {
			for(int i = 1; i <= n; ++ i) if(a[i] ^ b[i]) {
				if(a[i] == '0') L.push_back(i);
				else R.push_back(i);
			}			
		}
		swap(L, R);
		if(L.size() < R.size() || L.size() > R.size() + 1) {
			puts("-1");
			return;
		} else printf("%d\n", (int)L.size() + R.size());
	}
}

int main() {
	int c;
	for(cin >> c; c --;) m();
}
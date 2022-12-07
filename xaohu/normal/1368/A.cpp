#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int T, a, b, n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	cin >> T;
	while (T--) {
		cin >> a >> b >> n;
		int res = 0;
		while (max(a, b) <= n) {
			if (a > b) swap(a, b);
			a += b;
			res++;
		}
		cout << res << endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

int t, n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int a = 101, b = 0;
		rep(i, 1, n) {
			int x;
			cin >> x;
			if (x < a) 
				a = x, b = 0;
			if (x == a)
				b++;
		}
		cout << n - b << "\n";
	}		
	return 0;
}
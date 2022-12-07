#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int T, n, a[100];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		rep(j, 0, 2) {
			rep(i, 0, n)
				cin >> a[i];
			sort(a, a + n);
			rep(i, 0, n)
				cout << a[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
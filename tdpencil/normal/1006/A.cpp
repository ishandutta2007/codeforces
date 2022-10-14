#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector
const int mxN = 2e5;
int n, a[mxN];
void solve() {
	cin >> n;
	for(int i =0; i < n; i++)
		cin >> a[i];
	for(int i =0; i < n; i++)
		if(a[i]&1^1) {
			cout << a[i] -1 << " ";
		} else {
			cout << a[i] << " ";
		}

}
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T = 1;
	while(T--)
		solve();
}
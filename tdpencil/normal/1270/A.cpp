#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #include <bits/stdc++.h>

const int mxn = 2e5;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t; while(t--) solve();
	// solve();
}
const int mod = 1e9+7;
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> A(b);
	vector<int> B(c);

	for(int &i : A)
		cin >> i;
	for(int &i: B)
		cin >> i;

	cout <<( *max_element(A.begin(), A.end()) > *max_element(B.begin(), B.end()) ? "YES\n" : "NO\n" );

}
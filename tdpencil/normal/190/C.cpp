#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
int a[mxn];
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	solve();
}
string s;
string ans;
bool works = true;
void rec() {
	if(cin >> s) {
		ans.append(s);
		if(s == "pair") {
			ans += '<';
			rec();
			ans += ',';
			rec();
			ans += '>';
		}
	} else works = false;
}
void solve() {
	int n; cin >> n;
	rec();
	if(cin >>s || !works ) cout << "Error occurred";
	else cout << ans; 
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
const int mxN = 2e5+5;
const int mnN = 1e5+5;
const int grn = 105;
const int grN = 505;
const int griN = 1005;
const int mxGriN= 5005;
const int mxDP = 7005;
ll n, m;
void solve() {
	cin >> n;
	vector<int> f;
	for(int i=2;i*i<=n;i++)
		while(n%i==0)
			n/=i,f.push_back(i);
	if(n>1) f.push_back(n);
	cout << f.front() << f.back() << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; //cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cerr << "Case #" << case_num << ": ";
		solve();
	}
}
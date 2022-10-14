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
int n, m;
int a[mxN];
void solve() {
	cin >> n;
	m=-1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << 0 << "\n";
		return;
	}
	int c=0;
	for(int i = 0; i < n - 1; i++) {
		if(a[i] <= a[i+1]) {
			c=a[i+1]-a[i];
			break;
		}
	}
	for(int i = 0; i < n - 1; i++) {
		if(a[i] > a[i+1]) {
			int res=a[i]+c;
			int mod=res-a[i+1];
			m=mod;
			break;
		}
	}
	vector<int> di(n-1);
	for(int i = 0; i < n-1; i++) {
		di[i]=a[i+1]-a[i];
	}
	if(*max_element(di.begin(), di.end()) == *min_element(di.begin(), di.end())) {
		cout << 0 << "\n";
		return;
	}
	if(m == -1) {
		cout << -1 << "\n";
		return;
	}
	vector<int> toCheck;
	toCheck.push_back(a[0]%m);

	for(int i = 0; i < n - 1; i++) {
		toCheck.push_back( (toCheck.back() + c) % m); 
	}
	bool works = true;
	for(int i = 0; i < n; i++) {
		works &= a[i] == toCheck[i];
	}

	if(works) {
		cout << m << " " << c << "\n";
	} else {
		cout << -1 << "\n"; 
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cerr << "Case #" << case_num << ": ";
		solve();
	}
}
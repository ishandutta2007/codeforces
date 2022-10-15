#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string s;

bool ok(int x) {
	int i=-1;
	while(i<n) {
		if(i+x>=n)
			return 1;
		bool b=0;
		for(int j=1; j<=x; ++j) {
			if(s[i+j]=='R') {
				i+=j;
				b=1;
				break;
			}
		}
		if(!b)
			return 0;
	}
}

void solve() {
	cin >> s;
	n=s.size();
	int lb=1, rb=n+1;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		if(ok(mb))
			rb=mb;
		else
			lb=mb+1;
	}
	cout << lb << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}
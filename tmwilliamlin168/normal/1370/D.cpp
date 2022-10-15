#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, k, a[mxN];

bool ok(int x, int s) {
	int c=0;
	for(int i=0; i<n; ++i) {
		if(s||a[i]<=x) {
			++c;
			s^=1;
		}
	}
	return c>=k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	int lb=0, rb=1e9;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		if(ok(mb, 0)||ok(mb, 1))
			rb=mb;
		else
			lb=mb+1;
	}
	cout << lb;
}
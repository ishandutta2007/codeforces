#include <bits/stdc++.h>
using namespace std;

const int mxN=1000;
int n, m, a[1000], b[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n; ++i)
		cin >> b[i];
	double lb=0, rb=3e9;
	for(int it=0; it<100; ++it) {
		double mb=(lb+rb)/2, mb2=mb;
		bool ok=1;
		for(int i=0; i<n&&ok; ++i) {
			mb-=(mb+m)/a[i];
			ok&=mb>=0;
			mb-=(mb+m)/b[i];
			ok&=mb>=0;
		}
		if(ok)
			rb=mb2;
		else
			lb=mb2;
	}
	if(lb>2e9)
		cout << -1;
	else
		cout << fixed << setprecision(9) << lb;
}
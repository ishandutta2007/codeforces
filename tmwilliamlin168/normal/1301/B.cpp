#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[100000], n;

int solve(int x) {
	int l=0, r=1e9;
	for(int i=0; i+1<n; ++i) {
		if(a[i]==-1&&~a[i+1]) {
			l=max(l, a[i+1]-x);
			r=min(r, a[i+1]+x);
		} else if(a[i+1]==-1&&~a[i]) {
			l=max(l, a[i]-x);
			r=min(r, a[i]+x);
		}
	}
	return l>r?-1:l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> a[i];
		int lb=0, rb=1e9;
		for(int i=0; i+1<n; ++i)
			if(~a[i]&&~a[i+1])
				lb=max(abs(a[i]-a[i+1]), lb);
		while(lb<rb) {
			int mb=(lb+rb)/2;
			if(~solve(mb))
				rb=mb;
			else
				lb=mb+1;
		}
		cout << lb << " " << solve(lb) << "\n";
	}
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n, p[mxN];
pair<ll, int> a[mxN];

ll qry(int t, int i, int j, int k) {
	++i, ++j, ++k;
	cout << t << " " << i << " " << j << " " << k << endl;
	ll ans;
	cin >> ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	//find point after 0
	p[1]=1;
	for(int i=2; i<n; ++i) {
		if(qry(2, 0, p[1], i)<0)
			p[1]=i;
	}
	
	//find heights
	for(int i=1; i<n; ++i) {
		if(i==p[1])
			continue;
		a[i].first=qry(1, 0, p[1], i);
		a[i].second=i;
	}
	sort(a, a+n);

	int b1=2, b2=n-1;
	for(int i=2; i<n; ++i) {
		if(i<n-1&&qry(2, 0, a[i].second, a[i+1].second)>0)
			p[b1++]=a[i].second;
		else
			p[b2--]=a[i].second;
	}

	cout << 0;
	for(int i=0; i<n; ++i)
		cout << " " << p[i]+1;
	cout << endl;
}
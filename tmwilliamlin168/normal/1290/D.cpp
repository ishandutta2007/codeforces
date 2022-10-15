#include <bits/stdc++.h>
using namespace std;

int n, k, d;
bool a[1024];

bool ask(int i) {
	cout << "? " << i+1 << endl;
	char c;
	cin >> c;
	return c=='Y';
}

void reset() {
	cout << "R" << endl;
}

void solve(int l, int r) {
	int b=(r-l)/k;
	if(b==1) {
		for(int i=l; i<r; ++i)
			a[i]=ask(i);
	} else {
		int m=(l+r)/2;
		solve(l, m);
		solve(m, r);
		for(int i=1; i<b; i+=2) {
			for(int j=0; j<b; ++j) {
				for(int c=l+j*k/2; c<l+(j+1)*k/2; ++c)
					a[c]=a[c]||ask(c);
				for(int c=m+(j+i)%b*k/2; c<m+((j+i)%b+1)*k/2; ++c)
					a[c]=a[c]||ask(c);
			}
			reset();
		}
		for(int i=0; i<b; i+=2) {
			for(int c=l; c<l+k/2; ++c)
				ask(c);
			for(int c=m+i*k/2; c<m+(i+1)*k/2; ++c)
				a[c]=a[c]||ask(c);
		}
	}
	reset();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	if(n<2) {
		cout << "! 1";
		return 0;
	}
	k=max(k, 2);
	solve(0, n);
	for(int i=0; i<n; ++i)
		d+=!a[i];
	cout << "! " << d;
}
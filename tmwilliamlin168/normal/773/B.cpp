#include <bits/stdc++.h>
using namespace std;
 
const int mxN=120;
int n, a[mxN][5], s[5], ans=1e9;
 
int sc(int x, int y, int t) {
	if(t==-1)
		return 0;
	int m;
	if(2*x>y)
		m=500;
	else if(4*x>y)
		m=1000;
	else if(8*x>y)
		m=1500;
	else if(16*x>y)
		m=2000;
	else if(32*x>y)
		m=2500;
	else
		m=3000;
	return m/250*(250-t);
}
 
void test(int x) {
	int s1=0, s2=0;
	for(int i=0; i<5; ++i) {
		if(a[0][i]<0&&a[1][i]<0)
			continue;
		int ns=s[i];
		if(~a[0][i]&&~a[1][i]&&a[1][i]<a[0][i])
			ns+=x;
		s1+=sc(ns, n+x, a[0][i]);
		s2+=sc(ns, n+x, a[1][i]);
	}
	if(s1>s2)
		ans=min(ans, x);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<5; ++j) {
			cin >> a[i][j];
			if(~a[i][j])
				++s[j];
		}
	}
	for(int i=0; i<=31*n; ++i)
		test(i);
	cout << (ans>=1e9?-1:ans);
}
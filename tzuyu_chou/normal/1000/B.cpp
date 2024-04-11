#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int a[mxN+2], s[mxN+2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, ans;
	cin >> n >> m;
	++n;
	for(int i=1; i<n; ++i)
		cin >> a[i];
	if(n&1)
		a[n++]=m;
//	for(int i=0; i<n; ++i)
//		cout << a[i] << " ";
//	cout << endl;
	for(int i=n-2; i>=0; --i) {
		s[i]=s[i+1];
		if(i&1^1)
			s[i]+=a[i+1]-a[i];
	}
	ans=s[0];
//	cout << s[0] << endl;
	for(int i=0; i<n; ++i) {
		if(i&1^1)
			continue;
		if(a[i-1]!=a[i]-1)
			ans=max(s[0]+(m-(a[i]-1))-2*(s[i]+1), ans);
		if(i+1>=n||a[i+1]!=a[i]+1)
			ans=max(s[0]+(m-(a[i]+1))-2*s[i], ans);
	}
	cout << ans;
}
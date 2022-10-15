#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=1e6;
int n, a[mxN], nl[mxN], nr[mxN];
ll ans;
 
void solve() {
	for(int i=0; i<n; ++i) {
		nl[i]=i-1;
		while(~nl[i]&&a[nl[i]]<a[i])
			nl[i]=nl[nl[i]];
	}
	for(int i=n-1; ~i; --i) {
		nr[i]=i+1;
		while(nr[i]<n&&a[nr[i]]<=a[i])
			nr[i]=nr[nr[i]];
		ans+=(ll)a[i]*(nr[i]-i)*(i-nl[i]);
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	solve();
	for(int i=0; i<n; ++i)
		a[i]=-a[i];
	solve();
	cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e6, M=1e9+7;
int n, k, l[mxN], r[mxN];
ll a[mxN], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k, --k;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		l[i]=i-1;
		while(l[i]>=0&&a[l[i]]<a[i])
			l[i]=l[l[i]];
	}
	for(int i=n-1; i>=0; --i) {
		r[i]=i+1;
		while(r[i]<n&&a[r[i]]<=a[i])
			r[i]=r[r[i]];
	}
	for(int i=0; i<n; ++i) {
		l[i]=i-l[i];
		r[i]=r[i]-i;
		if(l[i]>r[i])
			swap(l[i], r[i]);
		ll b=(l[i]-1)/k+1, c=(r[i]-1)/k+1, d=(l[i]+r[i]-2)/k+1, e=d-c;
		ans+=(b+k*b*(b-1)/2)%M*a[i]%M;
		ans+=l[i]*(c-b)%M*a[i]%M;
		ans+=(e*((l[i]+r[i]-2)%k+1)+k*e*(e-1)/2)%M*a[i]%M;
		ans+=M-a[i];
	}
	cout << ans%M;
}
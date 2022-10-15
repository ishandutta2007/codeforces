#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll a[100000];

ll solve(ll a[100000], int n) {
	ll msf=-1e15, ans=-1e15;
	for(int i=0; i<n; ++i) {
		msf=max(msf, 0ll)+a[i];
		ans=max(ans, msf);
	}
	return ans;
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
		ll a1=0, a2=solve(a, n-1);
		for(int i=0; i<n; ++i)
			a1+=a[i];
		reverse(a, a+n);
		a2=max(a2, solve(a, n-1));
		cout << (a1>a2?"YES":"NO") << "\n";
	}
}
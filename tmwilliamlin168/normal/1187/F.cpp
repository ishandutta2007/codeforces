#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n;
ll l[mxN], r[mxN], e[mxN-1];
ll ans;

ll iv(ll a, ll m) {
	return a<=1?1:(1-iv(m%a, a)*m)/a+m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> l[i];
	for(int i=0; i<n; ++i)
		cin >> r[i];
	ans=(ll)n*n%M;
	ll es=0;
	for(int i=0; i+1<n; ++i) {
		int same=max(min(r[i], r[i+1])-max(l[i], l[i+1])+1, 0ll);
		e[i]=same*iv((r[i]-l[i]+1)*(r[i+1]-l[i+1]+1)%M, M)%M;
		ans=(ans+(M-2*n)*e[i])%M;
		es=(es+e[i])%M;
	}
	ans=(es*es+ans)%M;
	for(int i=0; i<n-1; ++i) {
		ans=(ans-e[i]*e[i]%M+M+e[i])%M;
	}
	for(int i=0; i+1<n-1; ++i) {
		int same=max(min({r[i], r[i+1], r[i+2]})-max({l[i], l[i+1], l[i+2]})+1, 0ll);
		ll f=same*iv((r[i]-l[i]+1)*(r[i+1]-l[i+1]+1)%M*(r[i+2]-l[i+2]+1)%M, M)%M;
		ans=(ans-2*e[i]*e[i+1]%M+M+2*f)%M;
	}
	cout << ans;
}
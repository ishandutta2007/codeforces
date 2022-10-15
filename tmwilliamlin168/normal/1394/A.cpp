#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, d, m;
	cin >> n >> d >> m;
	vector<ll> a1, a2;
	for(int i=0, a; i<n; ++i) {
		cin >> a;
		if(a>m)
			a2.push_back(a);
		else
			a1.push_back(a);
	}
	for(int i=0; i<d; ++i)
		a1.push_back(0);
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	ll ans=0, s=0;
	for(int b : a1)
		s+=b;
	ans=s;
	for(int i=(int)a2.size()-1, j=0; ~i; --i) {
		while(j<a1.size()&&j+i<(ll)d*(a2.size()-i))
			s-=a1[j++];
		s+=a2[i];
		if(j+i>=(ll)d*(a2.size()-i))
			ans=max(ans, s);
	}
	cout << ans;
}
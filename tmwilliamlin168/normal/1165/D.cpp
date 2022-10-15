#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF = 8000ll*1000*1000*1000;

void solve() {
	int n;
	cin >> n;
	vector<ll> d(n);
	ll lcm=1;
	for(int i=0; i<n; ++i) {
		cin >> d[i];
		lcm = min(lcm*d[i]/__gcd(lcm,d[i]),INF);
	}
	//cout << "l " << lcm << endl;
	sort(d.begin(),d.end());
	for(int i=2; i*i<=d[0]; ++i) {
		if(d[0]%i)
			continue;
		cout << "-1\n";
		return;
	}
	if(lcm >= INF) {
		cout << "-1\n";
		return;
	}
	if(d.back()==lcm) {
		for(int i=0; i+1<d.size(); ++i) {
			if(d[i]*d[0]!=d[i+1]) {
				cout << "-1\n";
				return;
			}
		}
		cout << lcm*d[0] << "\n";
		return;
	}
	vector<ll> d2;
	for(ll i=2; i*i<=lcm; ++i) {
		if(lcm%i)
			continue;
		d2.push_back(i);
		if(i*i<lcm)
			d2.push_back(lcm/i);
	}
	sort(d2.begin(),d2.end());
	if(d!=d2) {
		cout << "-1\n";
	} else {
		cout << lcm << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}
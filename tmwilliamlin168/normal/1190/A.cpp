#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	int m, di=0, ans=0;
	cin >> n >> m >> k;
	set<ll> s;
	for(int i=0; i<m; ++i) {
		ll pi;
		cin >> pi, --pi;
		s.insert(pi);
	}
	while(di<m) {
		auto it=s.begin();
		ll page=(*it-di)/k;
		while(s.size()&&(*s.begin()-di)/k<=page) {
			s.erase(s.begin());
		}
		di=m-s.size();
		ans++;
	}
	cout << ans;
}
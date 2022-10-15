#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll f(int y) {
	vector<ll> d;
	for(int i=0; y; ++i) {
		d.push_back(min(y, i?9:8));
		y-=d.back();
	}
	ll ans=0;
	while(d.size()) {
		ans=ans*10+d.back();
		d.pop_back();
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		ll p10=10, ans=LLONG_MAX;
		for(int x=0; x<=16; ++x, p10*=10) {
			for(int i=0; i<=9; ++i) {
				int d=min(10-i, k+1);
				int n2=n-(k+1-d)-x*9*d;
				for(int j=0; j<=k; ++j)
					n2-=(i+j)%10;
				if(n2>=0&&n2%(k+1)==0) {
					ll e=f(n2/(k+1));
					ans=min(ans, (e+1)*p10-10+i);
				}
			}
		}
		cout << (ans>=LLONG_MAX?-1:ans) << "\n";
	}
}
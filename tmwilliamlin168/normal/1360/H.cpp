#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> a;
		for(int i=0; i<n; ++i) {
			string s;
			cin >> s;
			a.push_back(0);
			for(int j=0; j<m; ++j)
				a.back()|=(s[j]&1ll)<<m-1-j;
		}
		ll lb=0, rb=(1ll<<m)-1;
		ll k=((1ll<<m)-n-1)/2;
		while(lb<rb) {
			ll mb=(lb+rb)/2, c=mb+1;
			for(ll b : a)
				if(b<=mb)
					--c;
			//cout << mb << " " << c << endl;
			if(c>=k+1)
				rb=mb;
			else
				lb=mb+1;
		}
		for(int i=m-1; ~i; --i)
			cout << (lb>>i&1);
		cout << "\n";
	}
}
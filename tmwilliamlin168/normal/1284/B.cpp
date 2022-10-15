#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, s[100000], m;
vector<int> mn, mx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		int l;
		cin >> l;
		bool a=0;
		for(int j=0; j<l; ++j) {
			cin >> s[j];
			if(j)
				a|=s[j]>s[j-1];
		}
		if(a) {
			++m;
		} else {
			mn.push_back(s[l-1]);
			mx.push_back(s[0]);
		}
	}
	sort(mn.begin(), mn.end());
	sort(mx.begin(), mx.end());
	ll ans=(ll)m*n;
	for(int a : mn) {
		ans+=m+mx.size()-(upper_bound(mx.begin(), mx.end(), a)-mx.begin());
	}
	cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, s;

void solve() {
	cin >> n >> s;
	vector<ll> a, b;
	ll s2=0;
	ll mx=0;
	for(int i=0; i<n; ++i) {
		ll ai;
		cin >> ai;
		a.push_back(ai);
		if(s2<=s) {
			s2+=ai;
			b.push_back(ai);
			mx=max(mx, ai);
		}
	}
	ar<int, 2> ans=s2<=s?ar<int, 2>{n, -1}:ar<int, 2>{(int)b.size()-1, -1};
	if(s2>s) {
	int sk=find(b.begin(), b.end(), mx)-b.begin();
		//cout << mx << endl;
	b.erase(find(b.begin(), b.end(), mx));
	s2-=mx;
	for(int i=b.size()+1; i<n; ++i) {
		if(s2+a[i]<=s) {
			s2+=a[i];
			b.push_back(a[i]);
		} else
			break;
	}
	ans=max(ar<int, 2>{(int)b.size(), sk}, ans);
	}
	cout << ans[1]+1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
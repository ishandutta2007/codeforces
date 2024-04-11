#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p, k, a[mxN];

void solve() {
	cin >> n >> p >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int ans=0, p2=0;
	for(int i=0; i<k; ++i) {
		int ca=0;
		//for(int j=0; j<i; ++j) {
			//p2+=a[j];
			//if(p2<=p)
				//ca=j+1;
		//}
		if(i) {
			p2+=a[i-1];
			if(p2<=p)
				ca=i;
		}
		int p3=p2;
		for(int j=i+k-1; j<n; j+=k) {
			p3+=a[j];
			if(p3<=p)
				ca=j+1;
		}
		ans=max(ans, ca);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
vector<ar<int, 3>> v;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	for(int a=1; a<=2e4; ++a) {
		for(int b=a; b<=2e4; b+=a) {
			for(int c=b; c<=2e4; c+=b) {
				v.push_back({a, b, c});
			}
		}
	}
 
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		ar<int, 4> ans={(int)1e9};
		for(ar<int, 3> d : v)
			ans=min(ar<int, 4>{abs(a-d[0])+abs(b-d[1])+abs(c-d[2]), d[0], d[1], d[2]}, ans);
		cout << ans[0] << "\n" << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
	}
}
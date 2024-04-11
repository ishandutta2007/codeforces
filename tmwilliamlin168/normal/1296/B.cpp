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
		int s;
		cin >> s;
		int ans=0;
		while(s) {
			if(s>=10) {
				int t=s/10;
				s-=t*10;
				s+=t;
				ans+=t*10;
			} else {
				ans+=s;
				s/=10;
			}
		}
		cout << ans << "\n";
	}
}
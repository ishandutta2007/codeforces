#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n;
ll k;
string s, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> s >> t;
	ll a1=0, a2=0, ans=0;
	for(int i=0; i<n; ++i) {
		a1=a1*2;
		a2=a2*2;
		if(s[i]=='b')
			++a1;
		if(t[i]=='b')
			++a2;
		ans+=min(a2-a1+1, k);
		if(a2-a1+1>=k) {
			ans+=(n-1-i)*k;
			cout << ans;
			return 0;
		}
		a2-=a1;
		a1=0;
	}
	cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n;
string s;
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	ans=(ll)n*(n-1)/2;
	for(int i=0; i<n; ++i) {
		int l=i-1, r=i+1;
		while(~l&&s[l]^s[i])
			--l;
		while(r<n&&s[r]^s[i])
			++r;
		ans-=(i-1-l)+(r-i-1);
	}
	for(int i=1; i<n; ++i)
		if(s[i-1]^s[i])
			++ans;
	cout << ans;
}
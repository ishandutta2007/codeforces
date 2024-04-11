#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
string s;
 
ll test(int a, int b) {
	ll dp0=0, dp1=0;
	for(int i=0; i<s.size(); ++i) {
		if(s[i]-'a'==b)
			dp1+=dp0;
		if(s[i]-'a'==a)
			++dp0;
	}
	return dp1;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> s;
	ll ans=0;
	for(int i=0; i<26; ++i) {
		for(int j=0; j<26; ++j) {
			ans=max(ans, test(i, j));
		}
		ll c=0;
		for(int j=0; j<s.size(); ++j)
			c+=s[j]-'a'==i;
		ans=max(c, ans);
	}
	cout << ans;
}
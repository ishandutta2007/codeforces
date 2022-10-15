#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s="codeforces";
	ll k;
	cin >> k;
	int c[10];
	for(int i=0; i<10; ++i) {
		c[i]=1;
	}
	int l=0;
	while(1) {
		ll n=1;
		for(int i=0; i<10; ++i)
			n*=c[i];
		if(n>=k)
			break;
		++c[l];
		l=(l+1)%10;
	}
	for(int i=0; i<10; ++i)
		for(int j=0; j<c[i]; ++j)
			cout << s[i];
}
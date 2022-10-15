#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, c[mxN], b[mxN], p[mxN], s, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0, ai; i<n; ++i) {
		cin >> ai, --ai;
		if(~ai)
			++c[ai];
	}
	for(int i=0; i<n; ++i) {
		cin >> b[i], --b[i];
		if(~b[i])
			p[b[i]]=i;
	}
	if(!c[0]) {
		//can we start placing already
		int i=0;
		while(b[i])
			++i;
		bool ok=1;
		for(int j=0; i+j<n&&ok; ++j)
			ok=b[i+j]==j;
		//next one is n-i
		for(int j=n-i; j<n&&ok; ++j)
			ok=c[j]||p[j]<j-(n-i);
		if(ok) {
			cout << i;
			return 0;
		}
	}
	//we need to retrieve the one first
	s=0;
	while(!c[0]) {
		if(~b[s])
			++c[b[s]];
		++s;
	}
	//each element must have already been collected or will be collected before it's required
	ans=s+n;
	for(int i=0; i<n; ++i)
		if(!c[i])
			ans=max(s+n+p[i]-(s-1)-i, ans);
	cout << ans;
}
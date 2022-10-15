#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	int wi=0;
	while(s[wi]!='*'&&wi<n)
		++wi;
	if(wi>=n) {
		cout << (s==t?"YES":"NO");
		return 0;
	}
	bool ok=1;
	for(int i=0; i<wi&&ok; ++i)
		ok=s[i]==t[i];
	for(int i=0; n-1-i>wi&&ok; ++i)
		ok=s[n-1-i]==t[m-1-i];
	cout << (ok&&n-1<=m?"YES":"NO");
}
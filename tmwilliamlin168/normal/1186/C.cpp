#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	int n=a.size(), m=b.size();
	int c=0;
	for(char d : b)
		c^=d&1;
	for(int i=0; i<m-1; ++i)
		c^=a[i]&1;
	int ans=0;
	for(int i=m-1; i<n; ++i) {
		c^=a[i]&1;
		//cout << i << " " << c << endl;
		if(!c)
			++ans;
		c^=a[i-m+1]&1;
	}
	cout << ans;
}
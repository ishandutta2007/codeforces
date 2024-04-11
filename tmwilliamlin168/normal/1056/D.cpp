#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, p[100000], s[100000]={};
	cin >> n;
	for(int i=1; i<n; ++i)
		cin >> p[i], --p[i];
	for(int i=n-1; i>=0; --i) {
		if(!s[i])
			++s[i];
		if(i)
			s[p[i]]+=s[i];
	}
	sort(s, s+n);
	for(int i=0; i<n; ++i)
	    cout << s[i] << " ";
}
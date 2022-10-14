#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+5;
int n, a[mxN], l[mxN], r[mxN], ans[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	stack<int> s;
	for(int i=0; i<n; ++i) {
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			l[i]=s.top();
		else
			l[i]=-1;
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i=n-1; i>=0; i--) {
		while(!s.empty()&&a[s.top()]>=a[i])
			s.pop();
		if(!s.empty())
			r[i]=s.top();
		else 
			r[i]=n;
		s.push(i);
	}
	for(int i=0; i<n; ++i) {
		//cout << i << " " <<  l[i] << " " << r[i] << "\n";
		int sz=r[i]-l[i]-1;
		ans[sz]=max(ans[sz], a[i]);		
	}
	for(int i=n; i>=1; --i)
		ans[i]=max(ans[i], ans[i + 1]);
	for(int i=1; i<=n; ++i)
		cout << ans[i] << " ";
	return 0;
}
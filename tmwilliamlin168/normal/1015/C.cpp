#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, a[mxN];
ll m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		int ai, bi;
		cin >> ai >> bi;
		m-=ai;
		a[i]=ai-bi;
	}
	if(m>=0) {
		cout << 0;
		return 0;
	}
	sort(a, a+n);
	for(int i=0; i<n; ++i) {
		m+=a[n-1-i];
		if(m>=0) {
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
}
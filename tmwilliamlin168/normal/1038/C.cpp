#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, ia, ib;
ll a[mxN+1], b[mxN+1], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	for(int i=0; i<n; ++i)
		cin >> b[i];
	sort(b, b+n, greater<int>());
	while(ia<n||ib<n) {
		if(a[ia]>b[ib])
			ans+=a[ia++];
		else
			++ib;
		if(a[ia]>b[ib])
			++ia;
		else
			ans-=b[ib++];
	}
	cout << ans;
}
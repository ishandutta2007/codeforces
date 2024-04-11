#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=5e5;
int n;
ll a[mxN], ps[mxN+1], ans, m1[mxN+1], m2[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	m1[0]=m2[n]=INT_MAX;
	for(int i=0; i<n; ++i)
		cin >> a[i], ps[i+1]=abs(a[i])+ps[i], m1[i+1]=min(a[i], m1[i]);
	for(int i=n-1; i>=0; --i)
		m2[i]=min(a[i], m2[i+1]);
	if(n<=1) {
		cout << a[0];
		return 0;
	}
	ans=max(a[0]+ps[n]-ps[1]-abs(m2[1])-m2[1], a[n-1]+ps[n-1]-abs(m1[n-1])-m1[n-1]);
	for(int i=1; i<n-1; ++i)
		ans=max(a[i]+ps[n]-ps[i+1]-abs(m2[i+1])-m2[i+1]+ps[i]-abs(m1[i])-m1[i], ans);
	cout << ans;
}
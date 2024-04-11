#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int m=1;
string s;
ll ans, mn[mxN+2], mx[mxN+2];
array<int, 3> a[mxN+1];
array<ll, 2> b[2*mxN+2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for(char c : s) {
		if(c&1) {
			a[m][2]=a[m-1][2]+1;
			a[m][0]=a[m][1]=a[m-1][1];
			++m;
		} else
			++a[m-1][1];
	}
	for(ll i=0; m; ++i) {
		mn[0]=1e18;
		for(int j=0; j<m; ++j)
			mn[j+1]=min(a[j][0]-i*a[j][2], mn[j]);
		mx[m]=-1e18;
		for(int j=m-1; ~j; --j)
			mx[j]=max(a[j][1]-i*a[j][2], mx[j+1]);
		int m2=0;
		for(int j=0; j<m; ++j)
			if(mn[j]<=a[j][1]-i*a[j][2]||a[j][0]-i*a[j][2]<=mx[j+1])
				a[m2++]=a[j];
		m=m2;
		for(int j=0; j<m; ++j) {
			b[2*j]={a[j][0]-i*a[j][2], 1};
			b[2*j+1]={a[j][1]-i*a[j][2]+1, -1};
		}
		sort(b, b+2*m);
		for(int j=0, s=0; j<2*m; ++j) {
			if(j)
				ans+=(b[j][0]-b[j-1][0])*s*(s-1)/2;
			s+=b[j][1];
		}
	}
	cout << ans;
}
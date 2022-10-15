#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5;
int n, s, a[mxN];
long long ai, c[2], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		++c[s];
		cin >> ai, a[i]=__builtin_popcountll(ai);
		s^=a[i]&1;
		ans+=c[s];
	}
	for(int i=0; i<n; ++i) {
		int j1=i-1, b=0, d=0;
		while(j1>=0&&b+a[j1]<a[i]) {
			b+=a[j1];
			--j1;
		}
		c[0]=c[1]=0;
		for(int j2=i; ++j1<=i; ) {
			while(j2<n&&b+a[j2]<2*a[i]) {
				b+=a[j2];
				++c[b&1^d];
				++j2;
			}
			ans-=c[d];
			b-=a[j1];
			d^=a[j1]&1;
		}
	}
	cout << ans;
}
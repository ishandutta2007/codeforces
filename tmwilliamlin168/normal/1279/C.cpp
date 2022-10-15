#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, a[mxN], b[mxN], p[mxN];
bool c[mxN];

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		p[a[i]]=i;
	}
	memset(c, 0, n);
	for(int i=0; i<m; ++i) {
		cin >> b[i], --b[i];
		c[b[i]]=1;
	}
	ll ans=m;
	//for(int i=0; i<n; ++i)
		//if(!c[a[i]])
			//b[m++]=a[i];
	int mp=-1;
	for(int i=0; i<m; ++i) {
		if(p[b[i]]>mp) {
			ans+=2*(p[b[i]]-i);
			mp=p[b[i]];
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}
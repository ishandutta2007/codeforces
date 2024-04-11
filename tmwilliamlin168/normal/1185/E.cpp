#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e3;
int n, m, mnr[26], mnc[26], mxr[26], mxc[26];
string g[mxN], h[mxN];
bool ap[26];

void solve() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> g[i];
	}

	//find num snakes
	memset(ap, 0, sizeof(ap));
	int k=0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(g[i][j]^'.') {
				k=max(g[i][j]-'a'+1, k);
				ap[g[i][j]-'a']=1;
			}

	//find boundaries
	for(int i=0; i<k; ++i) {
		mnr[i]=mnc[i]=mxN;
		mxr[i]=mxc[i]=0;
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(g[i][j]^'.') {
				int l=g[i][j]-'a';
				mnr[l]=min(i, mnr[l]);
				mxr[l]=max(i, mxr[l]);
				mnc[l]=min(j, mnc[l]);
				mxc[l]=max(j, mxc[l]);
			}
		}
	}
	for(int i=0; i<k; ++i) {
		if(mnr[i]<mxr[i]&&mnc[i]<mxc[i]) {
			cout << "NO\n";
			return;
		}
	}
	
	//simulate
	for(int i=0; i<n; ++i)
		h[i]=string(m, '.');
	for(int l=0; l<k; ++l) {
		for(int i=mnr[l]; i<=mxr[l]; ++i) {
			for(int j=mnc[l]; j<=mxc[l]; ++j) {
				h[i][j]='a'+l;
			}
		}
	}

	bool ok=1;
	for(int i=0; i<n; ++i)
		ok&=g[i]==h[i];
	if(!ok) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << k << "\n";
	for(int i=k-2; i>=0; --i) {
		if(mnr[i]>mxr[i]||mnc[i]>mxc[i]) {
			mnr[i]=mxr[i]=mnr[i+1];
			mnc[i]=mxc[i]=mnc[i+1];
		}
	}
	for(int i=0; i<k; ++i) {
		cout << mnr[i]+1 << " " << mnc[i]+1 << " " << mxr[i]+1 << " " << mxc[i]+1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}
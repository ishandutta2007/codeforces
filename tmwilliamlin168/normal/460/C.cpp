#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[100000], b[100000], c[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, w;
	cin >> n >> m >> w;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	int lb=1, rb=(int)1e9+m;
	while(lb<rb) {
		int mb=(lb+rb+1)/2;
		for(int i=0; i<n; ++i)
			b[i]=max(mb-a[i], 0);
		memset(c, 0, 4*n);
		ll d=0, e=0;
		for(int i=0; i<n; ++i) {
			e+=c[i];
			int f=max(b[i]-e, 0ll);
			d+=f;
			e+=f;
			if(i+w<n)
				c[i+w]-=f;
		}
		if(d<=m)
			lb=mb;
		else
			rb=mb-1;
	}
	cout << lb;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, a[mxN][8], b[mxN], c[256];

ar<int, 3> chk(int x) {
	memset(c, -1, sizeof(c));
	for(int i=0; i<n; ++i) {
		b[i]=0;
		for(int j=0; j<m; ++j)
			if(a[i][j]>=x)
				b[i]|=1<<j;
		c[b[i]]=i;
	}
	for(int i=0; i<1<<m; ++i)
		for(int j=0; j<1<<m; ++j)
			if(~c[i]&&~c[j]&&(i|j)==(1<<m)-1)
				return {1, c[i], c[j]};
	return {0};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> a[i][j];
	int lb=0, rb=1e9;
	while(lb<rb) {
		int mb=(lb+rb+1)/2;
		if(chk(mb)[0])
			lb=mb;
		else
			rb=mb-1;
	}
	ar<int, 3> x=chk(lb);
	cout << x[1]+1 << " " << x[2]+1;
}
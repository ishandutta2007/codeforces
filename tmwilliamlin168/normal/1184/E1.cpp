#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxM=1e6;
int n, m, p[mxN], r[mxN], s, t;
array<int, 3> e[mxM];

int find(int x) {
	return x^p[x]?(p[x]=find(p[x])):x;
}

bool join(int x, int y) {
	if((x=find(x))==(y=find(y)))
		return 0;
	if(r[x]<r[y])
		swap(x, y);
	p[y]=x;
	r[x]+=r[x]==r[y];
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> e[i][1] >> e[i][2] >> e[i][0], --e[i][1], --e[i][2];
	}
	s=e[0][1], t=e[0][2];
	sort(e+1, e+m);
	iota(p, p+n, 0);
	int ans=1e9;
	for(int i=1; i<m; ++i) {
		join(e[i][1], e[i][2]);
		if(find(s)==find(t))
			ans=min(e[i][0], ans);
	}
	cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

const int mxN=25;
int n, a[mxN][3];
vector<array<int, 4>> v1, v2;
array<int, 3> ans{-1<<30};

void con(vector<array<int, 4>> &v, int l, int r, array<int, 4> b={0, 0, 0, 0}) {
	if(l>=r) {
		v.push_back(b);
		return;
	}
	con(v, l+1, r, {b[0]+a[l][1]-a[l][0], b[1]-a[l][0], b[2]-a[l][0], 3*b[3]});
	con(v, l+1, r, {b[0]+a[l][1], b[1]+a[l][2], b[2], 3*b[3]+1});
	con(v, l+1, r, {b[0]-a[l][0], b[1]+a[l][2]-a[l][0], b[2]-a[l][0], 3*b[3]+2});
}

void rec(int i, int p) {
	for(; p/=3; i%=p) {
		if(i/p==2)
			cout << "WL\n";
		else if(i/p==1)
			cout << "MW\n";
		else
			cout << "LM\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<3; ++j)
			cin >> a[i][j];
	con(v1, 0, n/2);
	con(v2, n/2, n);
	sort(v2.begin(), v2.end());
	for(array<int, 4> b : v1) {
		int p=lower_bound(v2.begin(), v2.end(), array<int, 4>{-b[0], -b[1], -1<<30})-v2.begin();
		if(p<v2.size()&&v2[p][0]==-b[0]&&v2[p][1]==-b[1])
			ans=max(array<int, 3>{-b[2]-v2[p][2], b[3], v2[p][3]}, ans);
	}
	if(ans[0]>-1e9) {
		rec(ans[1], v1.size());
		rec(ans[2], v2.size());
	} else
		cout << "Impossible";
}
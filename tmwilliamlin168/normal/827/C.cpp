#include <bits/stdc++.h>
using namespace std;

class FTree {
public:
	int *a, n;
	FTree() {}
	FTree(int n) {
		this->n=n;
		a = new int[n+1]();
	}
	void upd(int i, int x) {
		for(++i; i<=n; i+=i&-i)
			a[i]+=x;
	}
	int sum(int n) {
		int t=0;
		for(; n>0; n-=n&-n)
			t+=a[n];
		return t;
	}
} ftree[4][11][10];

inline int d(char c) {
	if(c=='A')
		return 0;
	if(c=='C')
		return 1;
	if(c=='G')
		return 2;
	return 3;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int n, q;
	cin >> s >> q;
	n=s.size();
	for(char &c : s)
		c=d(c);
	for(int i=0; i<4; ++i)
		for(int j=1; j<=10; ++j)
			for(int k=0; k<j; ++k)
				ftree[i][j][k]=FTree((n-k+j-1)/j);
	for(int i=0; i<n; ++i)
		for(int j=1; j<=10; ++j)
			ftree[s[i]][j][i%j].upd(i/j, 1);
	while(q--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int x;
			char c;
			cin >> x >> c;
			--x;
			for(int j=1; j<=10; ++j)
				ftree[s[x]][j][x%j].upd(x/j, -1);
			s[x]=d(c);
			for(int j=1; j<=10; ++j)
				ftree[s[x]][j][x%j].upd(x/j, 1);
		} else {
			int l, r, t=0;
			string e;
			cin >> l >> r >> e;
			--l, --r;
			for(int i=0; i<e.size()&&i+l<=r; ++i)
				t+=ftree[d(e[i])][e.size()][(i+l)%e.size()].sum((r-l-i)/e.size()+(i+l)/e.size()+1)-ftree[d(e[i])][e.size()][(i+l)%e.size()].sum((i+l)/e.size());
			cout << t << "\n";
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6;
int n, a[mxN], b[mxN], e[mxN][2];
string t[mxN];
bool c[mxN];

bool d(string &s, bool a, bool b) {
	if(s=="AND")
		return a&&b;
	if(s=="OR")
		return a||b;
	if(s=="XOR")
		return a^b;
	if(s=="NOT")
		return !a;
}

void dfs1(int i) {
	if(t[i]=="IN") {
		c[i]=a[i]==0;
		return;
	}
	dfs1(a[i]);
	if(t[i]=="NOT") {
		c[i]=!c[a[i]];
		return;
	}
	dfs1(b[i]);
	c[i]=d(t[i], c[a[i]], c[b[i]]);
}

void dfs2(int i, int j) {
	if(j!=-1)
		for(int k=0; k<2; ++k)
			e[i][k]=e[j][d(t[j], k, c[a[j]^b[j]^i])];
	if(t[i]!="IN") {
		dfs2(a[i], i);
		if(t[i]!="NOT")
			dfs2(b[i], i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> t[i] >> a[i], --a[i];
		if(t[i]!="NOT"&&t[i]!="IN")
			cin >> b[i], --b[i];
	}
	dfs1(0);
	e[0][1]=1;
	dfs2(0, -1);
	for(int i=0; i<n; ++i)
		if(t[i]=="IN")
			cout << e[i][a[i]==-1];
}
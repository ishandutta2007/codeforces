#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, a[mxN], mn=-1, cn;
vector<int> zs;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, s[100], c[100]={}, a=0, d=-1;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> s[i], --s[i];
		++c[s[i]];
	}
	bool b[100]={};
	for(int i=0; i<100; ++i) {
		b[i]=1;
		if(c[i]==1)
			++a;
		else if(c[i]>2)
			d=i;
	}
	if(a&1&&d==-1) {
		cout << "NO";
		return 0;
	}
	if(a&1)
		b[d]=0;
	a/=2;
	for(int i=0; i<100&&a; ++i)
		if(c[i]==1)
			b[i]=0, --a;
	cout << "YES\n";
	for(int i=0; i<n; ++i) {
		cout << (char)('A'+b[s[i]]);
		b[s[i]]=1;
	}
}
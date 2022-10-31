#include <bits/stdc++.h>
using namespace std;

int n,b,k,x,v, **a, MOD = 1e9+7;

int** make() {
	int** res = new int*[x];
	for (int i=0;i<x;i++) {
		res[i] = new int[x];
		for (int j=0;j<x;j++) res[i][j] = 0;
	}
	return res;
}
int** mult(int** b) {
	int** res = make();
	for (int i=0;i<x;i++)
		for (int k=0;k<x;k++)
			for (int j=0;j<x;j++)
				res[i][j] = (res[i][j]+1LL*a[i][k]*b[k][j])%MOD;
	return res;
}
int** pow(int p) {
	int** ans = make();
	for (int i=0;i<x;i++) ans[i][i] = 1;
	while (p) {
		if (p&1) ans = mult(ans);
		p>>=1;
		a = mult(a);
	}
	return ans;
}

int main() {
	cin >> n >> b >> k >> x;
	a = make();
	for (int i=0;i<n;i++) {
		cin >> v;
		for (int j=0;j<x;j++) a[j][(10*j+v)%x]+=1;
	}
	cout << pow(b)[0][k];
}
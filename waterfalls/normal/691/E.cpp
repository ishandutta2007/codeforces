#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > Matrix;
typedef long long ll;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

Matrix make(int a, int b) { return Matrix(a,vector<int>(b)); }
Matrix mult(Matrix a, Matrix b) {
	Matrix res = make(a.size(),b[0].size());
	for (int i=0;i<a.size();i++) {
		for (int j=0;j<b[0].size();j++) {
			for (int k=0;k<a[0].size();k++) {
				res[i][j] = add(res[i][j],mult(a[i][k],b[k][j]));
			}
		}
	}
	return res;
}
Matrix binpow(Matrix x, ll p) {
	Matrix ans = make(x.size(),x.size());
	for (int i=0;i<x.size();i++) ans[i][i] = 1;
	while (p) {
		if (p&1) ans = mult(ans,x);
		p>>=1;
		x = mult(x,x);
	}
	return ans;
}

int n;
ll k;
ll a[113];
Matrix adj;

int main() {
	scanf("%d%lld",&n,&k);
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	adj = make(n,n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			ll x = a[i]^a[j];
			if (__builtin_popcountll(x)%3==0) adj[i][j] = 1;
		}
	}
	adj = binpow(adj,k-1);
	int ans = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) ans = add(ans,adj[i][j]);
	}
	printf("%d\n",ans);

	return 0;
}
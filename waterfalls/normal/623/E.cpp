#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b, int mo=MOD) { return a+b-(a+b>=mo)*mo; }
int sub(int a, int b, int mo=MOD) { return a-b+(a-b<0)*mo; }
int mult(int a, int b, int mo=MOD) { return ((ll) a*b)%mo; }
int binpow(int a, int p, int mo=MOD) {
	int ans = 1;
	while (p) {
		if (p&1) ans = mult(ans,a,mo);
		p>>=1;
		a = mult(a,a,mo);
	}
	return ans;
}
int inv(int a, int mo=MOD) { return binpow(a,mo-2,mo); }

const int PRIME[3] = {1004535809,1007681537,1012924417}; // 2^20*{958,961,966}
const int gen[3] = {3,3,5}; // primitive roots

inline vector<int> fft(vector<int>& a, int k, int w, int p) {
	vector<int> prev(1<<k);
	int high = -1;
	for (int i=1;i<(1<<k);i++) {
		if (!(i&(i-1))) high+=1;
		prev[i] = prev[i^(1<<high)];
		prev[i]|=(1<<(k-1-high));
	}
	for (int& i: prev) i = a[i];
	vector<int> roots(1<<k);
	roots[0] = 1;
	for (int i=1;i<(1<<k);i++) roots[i] = mult(roots[i-1],w,p);
	vector<int> next(1<<k);
	for (int len=1;len<(1<<k);len*=2) {
		int rstep = (1<<k)/(len*2);
		for (int pdest=0;pdest<(1<<k);) {
			int p1 = pdest;
			for (int i=0;i<len;i++) {
				int val = mult(roots[i*rstep],prev[p1+len],p);
				next[pdest] = add(prev[p1],val,p);
				next[pdest+len] = sub(prev[p1],val,p);
				pdest+=1; p1+=1;
			}
			pdest+=len;
		}
		swap(prev,next);
	}
	return prev;
}

inline vector<int> multiply (vector<int>& a, vector<int> b) {
	int len = a.size()+b.size()-1;
	int k = 0;
	while ((1<<k)<=2*max(a.size(),b.size())) k+=1;
	a.resize(1<<k);
	b.resize(1<<k);
	vector<int> c[3];
	for (int r=0;r<3;r++) {
		int p = PRIME[r];
		int w = binpow(gen[r],(p-1)/(1<<k),p);
		vector<int> one = fft(a,k,w,p);
		vector<int> two = fft(b,k,w,p);
		c[r] = vector<int>(1<<k);
		for (int i=0;i<(1<<k);i++) c[r][i] = mult(one[i],two[i],p);
		c[r] = fft(c[r],k,inv(w,p),p);
		int rem = inv(1<<k,p);
		for (int& i: c[r]) i = mult(i,rem,p);
	}
	vector<int> res(len);
	for (int i=0;i<len;i++) {
		ll cur = (ll) mult(sub(c[1][i],c[0][i],PRIME[1]),inv(PRIME[0],PRIME[1]),PRIME[1])*PRIME[0]+c[0][i];
		ll cur2 = mult(sub(c[2][i],cur%PRIME[2],PRIME[2]),inv(mult(PRIME[0],PRIME[1],PRIME[2]),PRIME[2]),PRIME[2]);
		cur2 = add(mult(cur2%MOD,mult(PRIME[0],PRIME[1])),cur%MOD);
		res[i] = cur2;
	}
	return res;
}

int n,k;
int fact[30013];

vector<int> solve() {
	vector<int> ans(k+1);
	ans[0] = 1;
	vector<int> cur(k+1);
	for (int i=1;i<=k;i++) cur[i] = inv(fact[i]);
	for (int j=1;j<=n;j*=2) {
		if (n&j) {
			for (int i=0;i<=k;i++) {
				ans[i] = mult(ans[i],binpow(2,i*j));
			}
			ans = multiply(ans,cur);
			ans.resize(k+1);
		}
		vector<int> cur2(k+1);
		for (int i=0;i<=k;i++) {
			cur2[i] = mult(cur[i],binpow(2,i*j));
		}
		cur = multiply(cur2,cur);
		cur.resize(k+1);
	}
	return ans;
}

int main() {
	fact[0] = 1;
	for (int i=1;i<30013;i++) fact[i] = mult(fact[i-1],i);
	ll nn;
	scanf("%lld%d",&nn,&k);
	if (nn>k) return printf("0\n"), 0;
	n = min((int) nn,k);
	vector<int> res = solve();
	int ans = 0;
	for (int i=1;i<=k;i++) {
		res[i] = mult(res[i],fact[k]);
		res[i] = mult(res[i],inv(fact[k-i]));
		ans = add(ans,res[i]);
	}
	printf("%d\n",ans);

	return 0;
}
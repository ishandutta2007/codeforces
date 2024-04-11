#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }
int bpow(int a, int b=MOD-2) {
	int res = 1;
	while (b) {
		if (b&1) res = mult(res,a);
		b>>=1;
		a = mult(a,a);
	}
	return res;
}

int n,k,q;

int combo[200013];
bool prime[1000013];
vector<int> fact[1000013];
int phi[1000013];

void precalc() {
	combo[k] = 1;
	for (int i=k+1;i<200013;i++) {
		combo[i] = mult(combo[i-1],i);
		combo[i] = mult(combo[i],bpow(i-k));
	}
	for (int i=1;i<1000013;i++) {
		prime[i] = (i>1);
		phi[i] = i;
	}
	for (int i=1;i<1000013;i++) {
		for (int j=i;j<1000013;j+=i) {
			if (i>1 && j>i) prime[j] = 0;
			fact[j].push_back(i);
			if (prime[i]) phi[j] = phi[j]/i*(i-1);
		}
	}
}

int ans;
int has[1000013];
void insert(int x) {
	for (int i: fact[x]) {
		ans = sub(ans,mult(combo[has[i]],phi[i]));
		has[i]+=1;
		ans = add(ans,mult(combo[has[i]],phi[i]));
	}
}

int main() {
	scanf("%d%d%d",&n,&k,&q);
	precalc();
	for (int i=0;i<n+q;i++) {
		int x;
		scanf("%d",&x);
		insert(x);
		if (i>=n) printf("%d\n",ans);
	}

    return 0;
}
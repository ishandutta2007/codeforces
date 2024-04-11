#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int inv[2000013];
int fact[2000013], ifact[2000013];
int low[1000013];
vector<int> has[1000013];

int combo(int x, int y) {
	if (x<y) return 0;
	return mult(fact[x],mult(ifact[y],ifact[x-y]));
}
void precalc() {
	fact[0] = ifact[0] = 1;
	fact[1] = ifact[1] = inv[1] = 1;
	for (int i=2;i<2000013;i++) {
		fact[i] = mult(fact[i-1],i);
		inv[i] = mult(sub(0,MOD/i),inv[MOD%i]);
		ifact[i] = mult(ifact[i-1],inv[i]);
	}
	iota(low,low+1000013,0);
	for (int i=2;i<1000013;i++) {
		if (low[i]==i) {
			has[i] = { 1 };
			for (int j=i+i;j<1000013;j+=i) low[j] = min(low[j],i);
		} else {
			int j = i;
			int num = 0;
			while (j%low[i]==0) {
				j/=low[i];
				num+=1;
			}
			has[i] = has[j];
			has[i].push_back(num);
		}
	}
}

int q,r,n;

int main() {
	precalc();
	scanf("%d",&q);
	while (q--) {
		scanf("%d%d",&r,&n);
		if (r==0) printf("%d\n",1<<has[n].size());
		else {
			int ans = 1;
			for (int i: has[n]) {
				int cur = add(combo(r+i-1,i-1),combo(r+i,i));
				ans = mult(ans,cur);
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}
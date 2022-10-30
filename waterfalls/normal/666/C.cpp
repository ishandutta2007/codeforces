#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }
int inv(int x) {
	int p = MOD-2;
	int ans = 1;
	while (p) {
		if (p&1) ans = mult(ans,x);
		x = mult(x,x);
		p>>=1;
	}
	return ans;
}

int fact[200013], ifact[200013];
int pow25[200013], ipow25[200013];
int pow26[200013], ipow26[200013];
void precalc() {
	fact[0] = ifact[0] = pow25[0] = ipow25[0] = pow26[0] = ipow26[0] = 1;
	for (int i=1;i<200013;i++) {
		fact[i] = mult(fact[i-1],i);
		ifact[i] = inv(fact[i]);
		pow25[i] = mult(pow25[i-1],25);
		ipow25[i] = inv(pow25[i]);
		pow26[i] = mult(pow26[i-1],26);
		ipow26[i] = inv(pow26[i]);
	}
}

int combo(int i, int j) {
	int res = 1;
	res = mult(res,fact[i]);
	res = mult(res,ifact[j]);
	res = mult(res,ifact[i-j]);
	return res;
}

int q;
char buff[100013];
int n[100013];
vector<int> need[100013];
int ans[100013];

int arr[100013];
void process(int s) {
	for (int i=0;i<100013;i++) {
		arr[i] = combo(i+s-1,s-1);
		arr[i] = mult(arr[i],pow25[i]);
		arr[i] = mult(arr[i],pow26[100012-i]);
		if (i) arr[i] = add(arr[i],arr[i-1]);
	}
	for (int i: need[s]) {
		if (n[i]<s) {
			ans[i] = 0;
			continue;
		}
		ans[i] = arr[n[i]-s];
		ans[i] = mult(ans[i],ipow26[100012-(n[i]-s)]);
	}
}

int main() {
	precalc();
	scanf("%d %s",&q,&buff);
	int sz = strlen(buff);
	for (int i=0;i<q;i++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			scanf(" %s",buff);
			sz = strlen(buff);
		} else {
			scanf("%d",&n[i]);
			need[sz].push_back(i);
		}
	}
	for (int i=0;i<100013;i++) {
		if (need[i].size()>0) process(i);
	}
	for (int i=0;i<q;i++) {
		if (n[i]) printf("%d\n",ans[i]);
	}

	return 0;
}
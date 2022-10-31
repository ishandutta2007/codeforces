#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return ((ll) a*b)%MOD; }
int fix(ll x) { return sub(x%MOD,0); }

int n;
ll x[1000013], y[1000013];
int xsums[1000013], ysums[1000013];
int psums[1000013], pisums[1000013];

ll area(int a, int b, int c) {
	return y[a]*x[b]+y[b]*x[c]+y[c]*x[a]-x[a]*y[b]-x[b]*y[c]-x[c]*y[a];
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	for (int i=n+1;i<=2*n;i++) x[i] = x[i-n], y[i] = y[i-n];
	for (int i=1;i<=2*n;i++) {
		xsums[i] = add(xsums[i-1],fix(x[i]));
		ysums[i] = add(ysums[i-1],fix(y[i]));
		psums[i] = add(psums[i-1],fix(y[i]*x[i+1]-x[i]*y[i+1]));
		pisums[i] = add(pisums[i-1],mult(fix(y[i]*x[i+1]-x[i]*y[i+1]),sub(0,i)));
	}
	ll tot = 0;
	for (int i=2;i<n;i++) tot+=area(1,i,i+1);
	int ans = 0;
	int on = 1;
	ll cur = 0;
	for (int i=1;i<=n;i++) {
		while (cur+area(i,on,on+1)<=tot/2) {
			cur+=area(i,on,on+1);
			on+=1;
		}
		int res = 0;
		res = add(res,mult(on-i-1,sub(psums[i],psums[i-1])));
		res = add(res,sub(pisums[on-1],pisums[i]));
		res = add(res,mult(on,sub(psums[on-1],psums[i])));
		res = add(res,mult(fix(x[i]),sub(ysums[on],ysums[i+1])));
		res = sub(res,mult(fix(y[i]),sub(xsums[on],xsums[i+1])));

		ans = add(ans,mult(fix(tot),on-i-1));
		ans = sub(ans,mult(res,2));
		cur-=area(i,i+1,on);
	}
	printf("%d\n",ans);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n,a,b,t;
char s[500013];
int costr[500013], costl[500013];

int solve() {
	int res = 0;
	costr[0] = 1+b*(s[0]=='w');
	for (int i=1;i<n;i++) {
		costr[i] = costr[i-1]+a+1+b*(s[i]=='w');
	}
	for (int i=0;i<n;i++) {
		if (costr[i]<=t) res = i+1;
		costr[i]+=a*i;
	}
	costl[n-1] = a+1+b*(s[n-1]=='w');
	for (int i=n-2;i>=0;i--) {
		costl[i] = costl[i+1]+a+1+b*(s[i]=='w');
	}
	for (int i=0;i<n;i++) {
		int extra = upper_bound(costr,costr+n,t-costl[i])-costr-1;
		if (extra==-1) continue;
		res = max(res,n-i+extra+1);
	}
	res = min(res,n);
	return res;
}

int main() {
	scanf("%d%d%d%d %s",&n,&a,&b,&t,&s);
	int ans = solve();
	rotate(s,s+1,s+n);
	reverse(s,s+n);
	ans = max(ans,solve());
	printf("%d\n",ans);

	return 0;
}
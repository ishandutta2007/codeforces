#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,mv[200001][2],chk[200001],vis[200001];
lli power(lli a, lli p) {
	lli ret=1;
	while(p) {
		if(p&1) ret=ret*a;
		a=a*a;
		p>>=1;
	}
	return ret;
}

int main() {
	scanf("%d",&n);
	for(int i=0,v;i<n;i++) {
		scanf("%d",&v);
		for(int j=2;j*j<=v;j++) if(v%j==0) {
			int cnt=0;
			while(v%j==0) {
				v/=j; cnt++;
			}
			if(!mv[j][0] || mv[j][0] > cnt) {
				mv[j][1] = mv[j][0]; mv[j][0] = cnt;
			} else if(!mv[j][1] || mv[j][1] > cnt) {
				mv[j][1] = cnt;
			}
			chk[j]++;
		}
		if(v>1) {
			int j=v,cnt=1;
			if(!mv[j][0] || mv[j][0] > cnt) {
				mv[j][1] = mv[j][0]; mv[j][0] = cnt;
			} else if(!mv[j][1] || mv[j][1] > cnt) {
				mv[j][1] = cnt;
			}
			chk[v]++;
		}
	}

	for(int i=2;i<=200000;i++) if(!vis[i]) {
		for(lli j=1ll*i*i;j<=200000;j+=i) vis[j] = 1;
	}
	
	lli ans=1;
	for(int i=2;i<=200000;i++) {
		if(!vis[i] && chk[i] > n-2) {
			int idx = 1 - (n - chk[i]);
			ans = ans * power(i, mv[i][idx]);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
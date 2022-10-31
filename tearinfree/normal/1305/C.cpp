#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,lli>;

int power(int a,int p,int mod) {
	int r=1;
	while(p) {
		if(p&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod;
		p>>=1;
	}
	return r;
}
int n,m,arr[200000],cnt[1001];
int main() {
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++) scanf("%d",arr+i),cnt[arr[i]%m]++;
	for(int i=0;i<m;i++) if(cnt[i]>=2) {
		puts("0");
		return 0;
	}

	lli ans=1;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
		ans=ans*(abs(arr[i]-arr[j])%m)%m;
	}
	printf("%lld\n",ans);

	return 0;
}
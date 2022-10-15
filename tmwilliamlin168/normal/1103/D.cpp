#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e6, mxM=11;
int n, m, e[mxN];
ll k, g, p[mxM], b[mxM], dp[mxM+1][1<<mxM], ans=1e15, ck[1<<mxM];
array<ll, 3> a[mxN];
priority_queue<array<int, 2>> c[1<<mxM];
vector<int> d[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> a[i][0];
		g=__gcd(g, a[i][0]);
	}
	for(ll i=2; i*i<=g; ++i) {
		if(g%i)
			continue;
		p[m++]=i;
		while(g%i==0)
			g/=i;
	}
	if(g>1)
		p[m++]=g;
	for(int i=0; i<n; ++i) {
		cin >> e[i];
		ll a2=a[i][0];
		for(int j=0; j<m; ++j)
			while(a2%p[j]==0)
				a2/=p[j];
		a[i][0]/=a2;
		a[i][1]=e[i];
		a[i][2]=i;
	}
	sort(a, a+n);
	ck[0]=1;
	for(int l=0, r=0; l<n; l=r) {
		for(; r<n&&a[r][0]==a[l][0]; ++r);
		for(int i=0; i<m; ++i) {
			b[i]=1;
			while(a[l][0]%p[i]==0) {
				b[i]*=p[i];
				a[l][0]/=p[i];
			}
			for(int j=0; j<1<<i; ++j)
				ck[j|1<<i]=ck[j]*b[i];
		}
		for(int i=0; i<1<<m; ++i) {
			if(ck[i]<=k) {
				for(int j=l; j<min(r, l+m); ++j) {
					c[i].push({a[j][1], a[j][2]});
					if(c[i].size()>m)
						c[i].pop();
				}
			}
		}
	}
	for(int i=0; i<1<<m; ++i) {
		while(c[i].size()) {
			d[c[i].top()[1]].push_back(i);
			c[i].pop();
		}
	}
	memset(dp, 0x01, sizeof(dp));
	dp[0][0]=0;
	for(int i=0; i<n; ++i) {
		for(int k=m; k; --k) {
			for(int s : d[i]) {
				for(int j=(1<<m)-1-s; ; j=(j-1)&~s) {
					dp[k][j|s]=min(dp[k-1][j]+e[i], dp[k][j|s]);
					if(!j)
						break;
				}
			}
		}
	}
	for(int i=1; i<=m; ++i)
		ans=min(i*dp[i][(1<<m)-1], ans);
	cout << (m?(ans>1e14?-1:ans):0);
}
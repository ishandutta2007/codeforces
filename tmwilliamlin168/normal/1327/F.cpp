#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5, M=998244353, I2=(M+1)/2;
int n, k, m, c[mxN+1], lz[mxN], rz[mxN];
ar<int, 3> a[mxN];
ll ans=1, dp[mxN+1], p2[mxN+1], pI2[mxN+1];

void solve(int n, vector<ar<int, 2>> v) {
	v.insert(v.begin(), {-1, -1});
	dp[0]=1;
	ll s1=0, s2=0;
	for(int i=1, j=0; i<v.size(); ++i) {
		s1=(s1+dp[i-1])%M;
		s2=(s2+dp[i-1]*p2[v[i][1]-v[i-1][1]])%M;
		while(v[j][1]<v[i][0]) {
			s1=(s1+M-dp[j])%M;
			s2=(s2+M-dp[j]*p2[v[j+1][1]-v[j][1]]%M)%M;
			++j;
		}
		dp[i]=(s2+M-s1+(p2[v[j][1]-v[i][0]+1]+M-1)*p2[v[i][0]-v[j-1][1]-1]%M*dp[j-1])%M;
	}
	ans=ans*dp[v.size()-1]%M;
	while(v.back()[1]<n-1) {
		ans=ans*2%M;
		--n;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m;
	p2[0]=pI2[0]=1;
	for(int i=1; i<=n; ++i) {
		p2[i]=p2[i-1]*2%M;
		pI2[i]=pI2[i-1]*I2%M;
	}
	for(int i=0; i<m; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2], --a[i][0], --a[i][1];
	}
	sort(a, a+m);
	for(int j=0; j<k; ++j) {
		memset(c, 0, 4*(n+1));
		for(int i=0; i<m; ++i)
			if(a[i][2]>>j&1)
				++c[a[i][0]], --c[a[i][1]+1];
		int nz=0;
		for(int i=0; i<n; ++i) {
			c[i+1]+=c[i];
			nz+=!c[i];
			lz[i]=nz;
			rz[i]=c[i]?nz+1:nz;
		}
		vector<ar<int, 2>> v1;
		for(int i=0; i<m; ++i) {
			if(a[i][2]>>j&1^1) {
				if(rz[a[i][0]]-1>lz[a[i][1]]-1) {
					cout << 0;
					return 0;
				}
				v1.push_back({rz[a[i][0]]-1, lz[a[i][1]]-1});
			}
		}
		vector<ar<int, 2>> v2;
		for(ar<int, 2> a : v1) {
			if(v2.size()&&a[0]==v2.back()[0]&&a[1]>v2.back()[1])
				continue;
			while(v2.size()&&a[1]<=v2.back()[1])
				v2.pop_back();
			v2.push_back(a);
		}
		solve(nz, v2);
	}
	cout << ans;
}
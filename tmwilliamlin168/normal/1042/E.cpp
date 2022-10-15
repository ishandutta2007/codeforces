#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e3, M=998244353;
int n, m, a[mxN][mxN], si, sj;
ll dp[mxN*mxN], ans;
array<int, 3> b[mxN*mxN];

ll modI(ll a, ll m) {
	if((a%=m)<=1)
		return 1;
	return (1-modI(m%a, a)*m)/a+m;
}

void solve() {
	ll s0=0, s1=0, s2=0;
	for(int i=0; i<n*m; ++i) {
		int j=i;
		while(j+1<n*m&&b[j+1][0]==b[i][0])
			++j;
		if(i) {
			ll c=modI(i, M);
			for(int k=i; k<=j; ++k)
				ans=(c*dp[k]%M*((s2*b[k][1]+s1)*b[k][1]%M+s0)+ans)%M;
		}
		for(int k=i; k<=j; ++k) {
			s0=(b[k][1]*b[k][1]+s0)%M;
			s1=(M-2*b[k][1]+s1)%M;
			++s2;
		}
		i=j;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> a[i][j];
			b[i*m+j]={a[i][j], i, j};
		}
	}
	cin >> si >> sj, --si, --sj;
	sort(b, b+n*m, greater<array<int, 3>>());
	for(int i=0; i<n*m; ++i) {
		if(b[i][0]>a[si][sj])
			continue;
		int j=i;
		while(j+1<n*m&&b[j+1][0]==b[i][0])
			++j;
		ll c=modI(n*m-j-1, M);
		for(int k=i; k<=j; ++k) {
			dp[k]%=M;
			dp[k+1]+=dp[k];
			if(b[k][1]==si&&b[k][2]==sj)
				dp[k]=1;
			if(j+1<n*m)
				dp[j+1]+=c*dp[k]%M;
		}
		i=j;
	}
	reverse(b, b+n*m);
	reverse(dp, dp+n*m);
	solve();
	swap(n, m);
	for(int i=0; i<n*m; ++i)
		swap(b[i][1], b[i][2]);
	solve();
	cout << ans;
}
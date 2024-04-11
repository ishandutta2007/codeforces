#include <bits/stdc++.h>
using namespace std;

int n, a[100], ans, t;
vector<array<int, 2>> v;
char dp[101][101][10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	dp[0][0][0]=1;
	for(int i=0; i<n; ++t) {
		int k=1;
		while(i+k<n&&a[i+k]==a[i])
			++k;
		for(int b=0; b<=i+k; ++b)
			for(int j=0; j<=a[i]*b; ++j)
				for(int l=0; l<=min(k, b); ++l)
					if(j-l*a[i]>=0)
						dp[i+k][b][j]=min(dp[i+k][b][j]+dp[i][b-l][j-l*a[i]], 2);
		v.push_back({a[i], k});
		i+=k;
	}
	if(t<=2)
		ans=n;
	for(array<int, 2> b : v)
		for(int i=1; i<=b[1]; ++i)
			if(dp[n][i][i*b[0]]==1)
				ans=max(i, ans);
	cout << ans;
}
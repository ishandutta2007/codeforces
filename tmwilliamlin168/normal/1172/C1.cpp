#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=51, M=998244353, mxA=mxN*mxN;
int n, m, a[mxN], w[mxN], wt[2];
ll dp[mxN+1][mxN][mxN]; //i turns, j changes for dislikes, k changes for likes, not including current picture
ll iv[mxA];

int nw(int i, int c) {
	return a[i]?w[i]+c:w[i]-c;
}

void am(ll &a, ll b) {
	a=(a+b)%M;
}

void calc(int b) {
	//cout << "calc " << b << endl;
	wt[a[b]]=(wt[a[b]]+M-w[b])%M;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<=i; ++j) {
			for(int k=0; j+k<=i; ++k) {
				if(nw(b, i-j-k)<0||wt[0]-j<0)
					continue;
				ll f=iv[nw(b, i-j-k)+(wt[0]-j)+(wt[1]+k)];
				//cout << nw(b, i-j-k)+(wt[0]-j)+(wt[1]+k) << endl;
				//cout << nw(b, i-j-k) << " " << (wt[0]-j) << " " << (wt[1]+k) << endl;
				//cout << dp[i][j][k] << endl;
				//current picture
				am(dp[i+1][j][k], nw(b, i-j-k)*f%M*dp[i][j][k]);
				//disliked pictures
				am(dp[i+1][j+1][k], (wt[0]-j)*f%M*dp[i][j][k]);
				//liked pictures
				am(dp[i+1][j][k+1], (wt[1]+k)*f%M*dp[i][j][k]);
			}
		}
	}
	ll ans=0;
	for(int j=0; j<=m; ++j)
		for(int k=0; j+k<=m; ++k)
			ans+=dp[m][j][k]*nw(b, m-j-k)%M;//, cout << j << " " << k << " " << dp[m][j][k] << endl;
	cout << ans%M << "\n";
	wt[a[b]]=(wt[a[b]]+w[b])%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	iv[1]=1;
	for(int i=2; i<mxA; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n; ++i) {
		cin >> w[i];
		wt[a[i]]=(wt[a[i]]+w[i])%M;
	}
	for(int i=0; i<n; ++i)
		calc(i);
}
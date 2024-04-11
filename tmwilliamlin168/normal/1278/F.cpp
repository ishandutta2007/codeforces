#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
ll n, m, im;
int k;
ll dp1[5001][5001];

ll pm(ll b, ll p) {
	ll r=1;
	while(p) {
		if(p&1)
			r=r*b%M;
		b=b*b%M;
		p/=2;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	im=pm(m, M-2);
	dp1[0][0]=1;
	for(int i=1; i<=k; ++i) {
		for(int j=0; j<=i; ++j) {
			//form new group
			if(j)
				dp1[i][j]=dp1[i-1][j-1];
			//join some group
			dp1[i][j]=(dp1[i][j]+dp1[i-1][j]*j)%M;
		}
	}
	ll imp=im, ff=n, ans=0;
	for(int i=1; i<=k; ++i) {
		ans=(ans+dp1[k][i]*ff%M*imp)%M;
		//if(i<10)
			//cout << ans << endl;
		imp=imp*im%M;
		ff=ff*(n-i)%M;
	}
	cout << ans;
}
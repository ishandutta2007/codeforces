#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=40, MGC1=20;
int n, m, ps[3*mxN+1], pf[3*mxN+1], tt[MGC1][2];
string s;
ll ans, dp[mxN+1][MGC1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	m=s.size();
	if(m>=MGC1) {
		ps[m]=2;
		for(int i=0; i<m; ++i)
			ps[i]=ps[i+m+1]=ps[i+m+n+1]=s[i]-'0';
		for(int i=0; i<1<<(n-m); ++i) {
			for(int j=0; j<n-m; ++j)
				ps[j+2*m+1]=ps[j+2*m+n+1]=i>>j&1;
			int a=0;
			for(int j=1; j<2*n+m+1; ++j) {
				int k=pf[j-1];
				while(ps[k]!=ps[j]) {
					if(!k) {
						k=-1;
						break;
					}
					k=pf[k-1];
				}
				pf[j]=k+1;
				if(pf[j]>=m&&j-m+1<n+m+1)
					a=j-m+1;
			}
			ans+=n+m+1-a;
		}
	} else {
		for(int i=0; i<m; ++i) {
			string t1=s.substr(0, i);
			for(int j=0; j<2; ++j) {
				string t2=t1+(char)(j+'0');
				for(int k=t2.size(); k; --k) {
					bool ok=1;
					for(int l=0; l<k&&ok; ++l)
						ok=s[l]==t2[t2.size()-k+l];
					if(ok) {
						tt[i][j]=k;
						break;
					}
				}
			}
		}
		tt[m][0]=tt[m][1]=m;
		for(int i=0; i<1<<(m-1); ++i) {
			memset(dp, 0, sizeof(dp));
			int a=0;
			for(int j=0; j<m-1; ++j)
				a=tt[a][i>>j&1];
			dp[m-1][a]=1;
			for(int j=m-1; j<n; ++j) {
				for(int k=0; k<=m; ++k) {
					dp[j+1][tt[k][0]]+=dp[j][k];
					dp[j+1][tt[k][1]]+=dp[j][k];
				}
			}
			for(int j=0; j<=m; ++j) {
				a=j;
				for(int k=0; k<m-1; ++k)
					a=tt[a][i>>k&1];
				if(a>=m)
					ans+=dp[n][j];
			}
		}
	}
	cout << ans;
}
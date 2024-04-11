#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=200, M=1e9+7;
int n, m, a[mxN][2], b[2]={1, -1};
string s;
ll dp1[mxN+1][mxN+1][mxN], dp2[mxN+1][mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	n*=2;
	m=s.size();
	for(int i=0; i<m; ++i) {
		for(char c='('; c<=')'; ++c) {
			string t=s.substr(0, i)+c;
			for(int j=i+1; ; --j) {
				bool ok=1;
				for(int k=0; k<j&&ok; ++k)
					ok=t[i-k]==s[j-1-k];
				if(ok) {
					a[i][c-'(']=j;
					break;
				}
			}
		}
	}
	dp1[0][0][0]=1;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			for(int k=0; k<m; ++k) {
				if(!dp1[i][j][k])
					continue;
				dp1[i][j][k]%=M;
				for(int c=0; c<2-!j; ++c) {
					if(a[k][c]>=m)
						dp2[i+1][j+b[c]]+=dp1[i][j][k];
					else
						dp1[i+1][j+b[c]][a[k][c]]+=dp1[i][j][k];
				}
			}
		}
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(!dp2[i][j])
				continue;
			dp2[i][j]%=M;
			for(int c=0; c<2-!j; ++c)
				dp2[i+1][j+b[c]]+=dp2[i][j];
		}
	}
	cout << dp2[n][0]%M;
}
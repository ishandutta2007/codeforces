#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1000][1000], a;
string g1[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> g1[i];
		memset(dp[i], 0x3F, 4*m);
	}
	auto b1=[&](const int &i, const int &j) {
		if(g1[i][j]=='*')
			++a;
		else
			a=-1;
		dp[i][j]=min(a, dp[i][j]);
	};
	for(int i=0; i<n; ++i) {
		a=-1;
		for(int j=0; j<m; ++j)
			b1(i, j);
		a=-1;
		for(int j=m-1; j>=0; --j)
			b1(i, j);
	}
	for(int j=0; j<m; ++j) {
		a=-1;
		for(int i=0; i<n; ++i)
			b1(i, j);
		a=-1;
		for(int i=n-1; i>=0; --i)
			b1(i, j);
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(!dp[i][j])
				dp[i][j]=-1;
	auto b2=[&](const int &i, const int &j) {
		a=max(dp[i][j], a-1);
		if(a>=0)
			g1[i][j]='.';
	};
	for(int i=0; i<n; ++i) {
		a=0;
		for(int j=0; j<m; ++j)
			b2(i, j);
		a=0;
		for(int j=m-1; j>=0; --j)
			b2(i, j);
	}
	for(int j=0; j<m; ++j) {
		a=0;
		for(int i=0; i<n; ++i)
			b2(i, j);
		a=0;
		for(int i=n-1; i>=0; --i)
			b2(i, j);
	}
	int k=0;
	for(int i=0; i<n; ++i) {
		if(g1[i].find("*")!=string::npos) {
			cout << -1;
			return 0;
		}
		for(int j=0; j<m; ++j)
			k+=dp[i][j]>0;
	}
	cout << k << "\n";
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(dp[i][j]>0)
				cout << i+1 << " " << j+1 << " " << dp[i][j] << "\n";
}
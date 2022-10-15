#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, xi, yi;
map<int, array<int, 2>> mp[2];
array<long long, 3> dp[2][2];

bool operator <(const array<int, 2> &a, const array<int, 2> &b) {
	return a[0]<b[0]||a[1]>b[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--) {
		cin >> xi >> yi;
		int a=max(xi, yi);
		array<int, 2> b{xi, yi};
		if(mp[0].find(a)!=mp[0].end()) {
			if(b<mp[0][a])
				mp[0][a]=b;
			if(mp[1][a]<b)
				mp[1][a]=b;
		} else
			mp[0][a]=mp[1][a]=b;
	}
	int i=0;
	for(auto it1=mp[0].begin(), it2=mp[1].begin(); it1!=mp[0].end(); ++it1, ++it2, i^=1) {
		array<int, 2> a1=it1->second, a2=it2->second;
		int c=abs(a1[0]-a2[0])+abs(a1[1]-a2[1]);
		dp[i^1][0]={a2[0], a2[1], min(dp[i][0][2]+abs(dp[i][0][0]-a1[0])+abs(dp[i][0][1]-a1[1]), dp[i][1][2]+abs(dp[i][1][0]-a1[0])+abs(dp[i][1][1]-a1[1]))+c};
		dp[i^1][1]={a1[0], a1[1], min(dp[i][0][2]+abs(dp[i][0][0]-a2[0])+abs(dp[i][0][1]-a2[1]), dp[i][1][2]+abs(dp[i][1][0]-a2[0])+abs(dp[i][1][1]-a2[1]))+c};
	}
	cout << min(dp[i][0][2], dp[i][1][2]);
}
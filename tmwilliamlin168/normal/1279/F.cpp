#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, k, l, qu[mxN], qh, qt;
ar<int, 2> dp[mxN+1]; //min uncovered

ar<int, 2> chk(vector<int> v, int x) {
	memset(dp, 0, sizeof(dp[0])*(v.size()+1));
	ar<int, 2> dp2=dp[0];
	qh=qt=0;
	ar<int, 2> ans{(int)v.size(), 0};
	for(int i=1, j=0; i<=v.size(); ++i) {
		while(v[j]<=v[i-1]-l) {
			++j;
			dp2=min(ar<int, 2>{dp[j][0]-j, dp[j][1]}, dp2);
			if(qh<qt&&qu[qh]==j)
				++qh;
		}
		//can't cover j-1
		dp[i]={dp2[0]+j, dp2[1]};
		if(qh<qt)
			dp[i]=min(dp[i], dp[qu[qh]]);
		dp[i][0]+=x;
		++dp[i][1];
		while(qh<qt&&dp[qu[qt-1]]>dp[i])
			--qt;
		qu[qt++]=i;
		ans=min(ans, ar<int, 2>{(int)v.size()-i+dp[i][0], dp[i][1]});
	}
	return ans;
}

int solve(vector<int> v) {
	int lb=0, rb=n;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		if(chk(v, mb)[1]<=k)
			rb=mb;
		else
			lb=mb+1;
	}
	return chk(v, lb)[0]-k*lb;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> l;
	string s;
	cin >> s;
	vector<int> a, b;
	for(int i=0; i<n; ++i) {
		if(s[i]>='a'&&s[i]<='z')
			a.push_back(i);
		else
			b.push_back(i);
	}
	//cout << solve(a) << endl;
	//cout << solve(b) << endl;
	cout << min(solve(a), solve(b));
}
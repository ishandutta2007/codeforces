#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int* dishes = new int[n+1];
	for(int i=1; i<=n; ++i)
		cin >> dishes[i];
	int** pairs = new int*[n+1];
	for(int i=0; i<=n; ++i) {
		pairs[i]=new int[n+1];
		for(int j=0; j<=n; ++j)
			pairs[i][j]=dishes[j];
	}
	for(int i=0; i<k; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		pairs[x][y]+=c;
	}

	ll** dp = new ll*[1<<n];
	for(int i=0; i<1<<n; ++i) {
		dp[i]=new ll[n+1];
		for(int j=0; j<=n; ++j)
			dp[i][j]=-1;
	}
	dp[0][0]=0;
	ll _max=0;

	for(int i=1; i<1<<n; ++i) {
		if(__builtin_popcount(i)>m)
			continue;
		for(int j=0; j<n; ++j) {
			if(i&(1<<j)) {
				int prevI=i^(1<<j);
				for(int k=0; k<=n; ++k) {
					if(dp[prevI][k]!=-1) {
						if(dp[i][j+1]==-1)
							dp[i][j+1]=dp[prevI][k]+pairs[k][j+1];
						else
							dp[i][j+1]=max(dp[prevI][k]+pairs[k][j+1], dp[i][j+1]);
						_max=max(dp[i][j+1], _max);
					}
					//cout << "hi" << endl;
				}
			}
		}
	}

	cout << _max;

	return 0;
}
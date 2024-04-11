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

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sx, sy, n;
	cin >> sx >> sy >> n;
	int *x=new int[n], *y=new int[n];
	for(int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	int dist[26][26];
	for(int i=0; i<=n; ++i) {
		for(int j=0; j<=n; ++j) {
			if(i==j) continue;
			if(i==0||j==0) {
				int a=i+j-1, dx=sx-x[a], dy=sy-y[a];
				dist[i][j]=dx*dx+dy*dy;
			} else {
				int dx=x[i-1]-x[j-1], dy=y[i-1]-y[j-1];
				dist[i][j]=dx*dx+dy*dy;
			}
		}
	}
	int *dp = new int[1<<n];
	dp[0]=0;
	int **prev = new int*[1<<n];
	for(int i=0; i<1<<n; ++i)
		prev[i]=new int[2]();

	for(int i=1; i<1<<n; ++i) {
		int _min=INT_MAX, j=0;
		for(; j<n; ++j) {
			if(i&(1<<j)) {
				_min=dp[i^(1<<j)]+2*dist[0][j+1];
				prev[i][0]=j+1;
				prev[i][1]=i^(1<<j);
				break;
			}
		}
		for(int k=j+1; k<n; ++k) {
			if(i&(1<<k)) {
				int cur=dp[i^(1<<k)^(1<<j)]+dist[0][j+1]+dist[j+1][k+1]+dist[k+1][0];
				if(cur<_min) {
					_min=cur;
					prev[i][0]=(j+1)*100+(k+1);
					prev[i][1]=i^(1<<k)^(1<<j);
				}
			}
		}
		//cout << _min << endl;
		dp[i]=_min;
	}
	int i=(1<<n)-1;
	cout << dp[i] << "\n0 ";
	while(i!=0) {
		if(prev[i][0]>100)
			cout << prev[i][0]/100 << ' ' << prev[i][0]%100 << ' ';
		else
			cout << prev[i][0] << ' ';
		cout << "0 ";
		i=prev[i][1];
	}

	return 0;
}